#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Packet {
    int source;
    int dest;
    int time;
};

class Router {
public:
    deque<Packet> packetQueue;
    int memLimit;

    unordered_map<int, deque<int>> timesByDest;
    unordered_set<long long int> seen;

    Router(int memoryLimit) {
        memLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if (!packetQueue.empty() && packetQueue.back().time == timestamp){
            long long int identifier = getIdentifier(source, destination);
            if (seen.count(identifier)){
                return false;
            }
            seen.insert(identifier);
        }
        else {
            seen.clear();
            seen.insert(getIdentifier(source, destination));
        }
        
        if (packetQueue.size() == memLimit){
            Packet drop = packetQueue.front();
            packetQueue.pop_front();

            if (drop.time == packetQueue.back().time){
                seen.erase(getIdentifier(drop.source, drop.dest));
            }
            timesByDest[drop.dest].pop_front();
        }

        packetQueue.push_back({source, destination, timestamp});
        if (timesByDest.count(destination)){
            timesByDest[destination].push_back(timestamp);
        }
        else {
            timesByDest[destination] = deque<int>(1, timestamp);
        }

        return true;
    }
    
    vector<int> forwardPacket() {
        if (packetQueue.empty()){
            return {};
        }
        Packet front = packetQueue.front();
        packetQueue.pop_front();

        if (!packetQueue.empty() && packetQueue.back().time == front.time){
            seen.erase(getIdentifier(front.source, front.dest));
        }

        timesByDest[front.dest].pop_front();

        return {front.source, front.dest, front.time};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto& timeDeque = timesByDest[destination];

        auto front = lower_bound(timeDeque.begin(), timeDeque.end(), startTime);
        auto back = upper_bound(timeDeque.begin(), timeDeque.end(), endTime);
        return back-front;
    }

    long long int getIdentifier(int source, int dest){
        return (((long long int) source) << 32) + ((long long int) dest);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

int main(){
    Router* obj = new Router(2);
    obj->addPacket(2, 5, 1);
    obj->forwardPacket();
    obj->getCount(5, 1, 1);
}