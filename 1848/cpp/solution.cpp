#include <vector>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int low;
        int high;
        int n = nums.size();
        for (int i = 0; i < (n-start) || i <= start; i++){
            low = max(0, start - i);
            high = min(n-1, start + i);
            if (nums[low] == target || nums[high] == target){
                return i;
            }
        }
        return -1;
    }
};