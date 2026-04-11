#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices_map;
        for (int i = 0; i < nums.size(); i++){
            if (indices_map.find(nums[i]) != indices_map.end()){
                indices_map[nums[i]].push_back(i);
            }
            else {
                indices_map[nums[i]] = {i};
            }
        }
        bool valid = false;
        int res = __INT32_MAX__;
        for (auto it: indices_map){
            if (it.second.size() < 3){
                continue;
            }
            else {
                for (int i = 0; i < it.second.size() - 2; i++){
                    res = min(res, (it.second[i+2] - it.second[i])*2);
                    valid = true;
                }
            }
        }
        if (valid){
            return res;
        }
        return -1;
    }
};