#include <vector>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];

        if (a == b){
            return a;
        }
        if (a == nums[2] || a == nums[3]){
            return a;
        }
        
        for (int i = 2; i < nums.size(); i++){
            if (nums[i] == a || nums[i] == b){
                return nums[i];
            }
            a = b;
            b = nums[i];
        }
        return a;
    }
};