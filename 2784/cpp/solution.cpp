#include <vector>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int target_n = nums.size()-1;
        if (target_n <= 0){
            return false;
        }

        vector<int> counts = vector<int>(target_n, 0);

        for (int num: nums){
            if (num > target_n){
                return false;
            }
            counts[num-1]++;
        }

        for (int i = 0; i < counts.size()-1; i++){
            if (counts[i] != 1){
                return false;
            }
        }
        if (counts[target_n-1] == 2){
            return true;
        }
        return false;

    }
};