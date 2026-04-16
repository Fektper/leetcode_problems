#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        unordered_map<int, vector<int>> nums_indices;
        unordered_map<int, int> index_offsets;
        for (int i = 0; i < nums.size(); i++){
            if (nums_indices.find(nums[i]) != nums_indices.end()){
                index_offsets[i] = nums_indices[nums[i]].size();
                nums_indices[nums[i]].push_back(i);
            } else {
                nums_indices[nums[i]] = {i};
                index_offsets[i] = 0;
            }
        }

        vector<int> res = vector<int>(queries.size(), -1);
        int n = nums.size();
        int num;
        int idx;
        int dist;
        int a; int b;
        int offset; int low; int high;
        for (int i = 0; i < queries.size(); i++){
            idx = queries[i];
            num = nums[idx];

            if (nums_indices.find(num) == nums_indices.end() || nums_indices[num].size() == 1){
                continue;
            }
            offset = index_offsets[idx];

            dist = __INT32_MAX__;
            // Go to left
            low = nums_indices[num][(offset - 1 + nums_indices[num].size()) % nums_indices[num].size()];
            high = nums_indices[num][(offset + 1) % nums_indices[num].size()];

            a = max(low, idx) - min(low, idx);
            b = (min(low, idx) - max(low, idx) + n) % n;
            dist = min(dist, min(a, b));

            a = max(high, idx) - min(high, idx);
            b = (min(high, idx) - max(high, idx)+n) % n;
            dist = min(dist, min(a, b));
            
            res[i] = dist;

        }
        return res;
    }
};