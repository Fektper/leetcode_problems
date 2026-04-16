#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> nums_indices;
        for (int i = 0; i < nums.size(); i++){
            if (nums_indices.find(nums[i]) != nums_indices.end()){
                nums_indices[nums[i]].push_back(i);
            } else {
                nums_indices[nums[i]] = {i};
            }
        }

        vector<int> res = vector<int>(queries.size(), -1);
        int n = nums.size();
        int num;
        int idx;
        int dist;
        int a; int b;
        for (int i = 0; i < queries.size(); i++){
            idx = queries[i];
            num = nums[idx];

            if (nums_indices.find(num) == nums_indices.end() || nums_indices[num].size() == 1){
                continue;
            }
            dist = __INT32_MAX__;
            for (int j: nums_indices[num]){
                if (j == idx){
                    continue;
                }

                a = max(j, idx) - min(j, idx);
                b = (min(j, idx) - max(j, idx) + n) % n;
                dist = min(dist, min(a, b));
            }
            res[i] = dist;

        }
        return res;
    }
};