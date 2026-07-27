#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;

        for (int k = 2; k < n; k++){
            if (nums[i] < nums[j] && nums[k] > nums[i]){
                i = k;
            }
            else if (nums[k] > nums[j]){
                j = k;
            }
        }

        return (nums[i]-1) * (nums[j]-1);
    }
};