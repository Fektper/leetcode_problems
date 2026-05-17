#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> pos_queue;
        set<int> seen;

        seen.insert(start);
        pos_queue.push(start);

        int i;
        while (!pos_queue.empty()){
            i = pos_queue.front();
            pos_queue.pop();
            if (arr[i] == 0){
                return true;
            }
            if (i - arr[i] >= 0){
                if (seen.find(i-arr[i]) == seen.end()){
                    seen.insert(i-arr[i]);
                    pos_queue.push(i - arr[i]);
                }
            }
            if (i + arr[i] < n){
                if (seen.find(i + arr[i]) == seen.end()){
                    seen.insert(i + arr[i]);
                    pos_queue.push(i + arr[i]);
                }
            }
        }
        return false;
    }
};