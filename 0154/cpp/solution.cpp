#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // There exists not log(n) time solution for this problem!
        int min = nums[0];
        for (int num: nums){
            min = std::min(min, num);
        }
        return min;
    }
};