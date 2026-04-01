#include <queue>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

struct Robot{
    int pos;
    int hp;
    char dir;
    int order;
};

class RobotPosCompare{
public:
    bool operator() (Robot& a, Robot& b) const{
        return a.pos < b.pos;
    }
};

class RobotInsertOrder{
    public:
    bool operator() (Robot& a, Robot& b) const{
        return a.order < b.order;
    }
};


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        priority_queue<Robot, vector<Robot>, RobotPosCompare> rob_pos_queue;
        for (int i = 0; i < positions.size(); i++){
            rob_pos_queue.push({positions[i], healths[i], directions[i], i});
        }
        
        vector<Robot> robs;
        stack<Robot> nexts;

        while (!rob_pos_queue.empty()){
            nexts.push(rob_pos_queue.top());
            rob_pos_queue.pop();
        }

        Robot next;
        Robot cur;
        while (!nexts.empty()){
            next = nexts.top();
            nexts.pop();

            if (robs.size() == 0){
                // Empty list, no collission
                robs.push_back(next);
                continue;
            }
            if (next.dir == robs[robs.size()-1].dir || next.dir == 'R'){
                // Same direction (or next one moves right), no collission
                robs.push_back(next);
                continue;
            }
            // Next moves left and current top moves right
            bool died = false;
            while (!died && robs.size() > 0){
                cur = robs[robs.size()-1];
                if (cur.dir == next.dir){
                    break;
                }
                if (cur.hp < next.hp){
                    next.hp--;
                    robs.pop_back();
                    continue;
                }
                if (cur.hp == next.hp){
                    robs.pop_back();
                    died = true;
                    break;
                }
                else {
                    died = true;
                    robs[robs.size()-1].hp--;
                    break;
                }

            }
            if (!died){
                robs.push_back(next);
            }

        }

        sort(robs.begin(), robs.end(), RobotInsertOrder());
        vector<int> hps;
        for (Robot r: robs){
            hps.push_back(r.hp);
        }

        return hps;

    }
};

int main(){
    Solution solver = Solution();
    vector<int> positions = {3,5,2,6};
    vector<int> healths = {10,10,15,12};
    string directions = "RLRL";

    vector<int> res = solver.survivedRobotsHealths(positions, healths, directions);

    for (int r: res){
        std::cout << r << " - ";
    }
}