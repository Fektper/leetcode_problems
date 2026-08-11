#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sequential_end = 0;

        while (sequential_end < nums.size()-1){
            if (nums[sequential_end+1] == nums[sequential_end] +1){
                sequential_end++;
            }
            else {
                break;
            }
        }

        int prefix_sum = 0;
        for (int i = 0; i <= sequential_end; i++){
            prefix_sum += nums[i];
        }
        
        sort(nums.begin(), nums.end());
        int i = sequential_end;
        while (i < nums.size()){
            if (nums[i] < prefix_sum){
                i++;
                continue;
            }
            if (nums[i] > prefix_sum){
                return prefix_sum;
            }
            if (nums[i] == prefix_sum){
                prefix_sum++;
                i++;
                continue;
            }
        }
        return prefix_sum;
    }
};