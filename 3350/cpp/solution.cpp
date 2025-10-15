#include <vector>

using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int max_singuar_length = 0;
        int max_consecutive_length = 0;

        int previous_length = 0;

        int i = 0;
        int j = 0;
        int previous_num = -__INT32_MAX__ -1;
        while(i < nums.size()){
            j = 0;
            previous_num = -__INT32_MAX__ -1;
            while (i+j < nums.size() && nums[i+j] > previous_num){
                previous_num = nums[i+j];
                j++;
            }
            max_singuar_length = max(max_singuar_length, j);
            max_consecutive_length = max(max_consecutive_length, min(previous_length, j));
            previous_length = j;
            i = i+j;
        }
        return max(max_singuar_length / 2, max_consecutive_length);
    }
};
