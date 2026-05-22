#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid = (high + low) / 2;

        while (low < mid && mid < high){
            if (nums[low] <= target && nums[mid] >= target){
                high = mid;
            } 
            else if (nums[mid] <= target && nums[high] >= target){
                low = mid;
            }
            else if (nums[mid] < nums[low] ){
                high = mid;
            }
            else if (nums[high] < nums[mid]){
                low = mid;
            }
            else {
                return -1;
            }
            mid = (high + low) / 2;

        }

        if (nums[low] == target){
            return low;
        }
        if (nums[mid] == target){
            return mid;
        }
        if (nums[high] == target){
            return high;
        }
        return -1;

    }
};