#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int min_num = __INT32_MAX__;
        if (n <= 3){
            for (int num: nums){
                min_num = std::min(min_num, num);
            }
            return min_num;
        }

        int low = 0;
        int high = n-1;
        int mid = (high + low) / 2;

        while (low < mid && mid < high){
            if (nums[low] < nums[mid] && nums[mid] < nums[high]){
                return nums[low];
            }
            else if (nums[low] > nums[mid]){
                low = low;
                high = mid;
            }
            else { // nums[high] < nums[mid];
                low = mid;
                high = high;
            }
            mid = (low + high) / 2;
        }

        return min(nums[low], min(nums[high], nums[mid]));
    }
};