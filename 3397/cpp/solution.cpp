#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int previous_num = -__INT32_MAX__ - 1;
        int total_count = 0;

        for (int num: nums){
            if (num - k > previous_num){
                previous_num = num - k;
                total_count++;
                continue;
            }
            else if (num + k <= previous_num){
                continue;
            }

            previous_num++;
            total_count++;
        }
        return total_count;
    }
};