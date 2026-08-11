#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sequential_end = 0;
        set<int> values;

        while (sequential_end < nums.size()-1){
            if (nums[sequential_end+1] == nums[sequential_end] +1){
                sequential_end++;
            }
            else {
                break;
            }
        }

        int prefix_sum = 0;
        for (int i = 0; i < nums.size(); i++){
            values.insert(nums[i]);
            if (i <= sequential_end){
                prefix_sum += nums[i];
            }
        }
        while(values.find(prefix_sum) != values.end()){
            prefix_sum++;
        }
        return prefix_sum;
    }
};