#include <vector>

using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int previousLength = 0;
        int currentLength = 0;
        int previousVal = -__INT32_MAX__ - 1;
        int i = 0;
        int j = 0;
        while (i < nums.size()){
            previousVal = -__INT32_MAX__ - 1;
            j = 0;
            while (i+j < nums.size()){
                if (nums[i+j] > previousVal){
                    previousVal = nums[i+j];
                    j++;
                }
                else {
                    break;
                }
            }
            currentLength = j;
            if (currentLength >= 2*k || (previousLength >= k && currentLength >= k)){
                return true;
            }

            i = i+j;
            previousLength = currentLength;
        }

        return false;
    }
};
int main(){
    vector<int> test = {-3,-19,-8,-16};
    Solution solver = Solution();
    solver.hasIncreasingSubarrays(test, 2);
}