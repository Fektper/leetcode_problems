#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> dry_times;
        unordered_map<int, int> last_rain;
        vector<int> res(rains.size(), 2);

        vector<int>::iterator pt;
        for (int i = 0; i < rains.size(); i++){
            if (rains[i] == 0){
                dry_times.push_back(i);
                continue;
            }
            res[i] = -1;
            if (last_rain.find(rains[i]) == last_rain.end()){
                last_rain[rains[i]] = i;
            }
            else {
                pt = lower_bound(dry_times.begin(), dry_times.end(), last_rain[rains[i]] + 1);
                if (pt == dry_times.end()){
                    return {};
                }
                res[*pt] = rains[i];
                last_rain[rains[i]] = i;
                dry_times.erase(pt);
            }
        }
        return res;
    }
};

int main(){
    vector<int> rains = {1,2,0,0,2,1};
    Solution solver = Solution();
    solver.avoidFlood(rains);
}