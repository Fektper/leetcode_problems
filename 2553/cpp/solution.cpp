#include <vector>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) { // nums[i] > 0
        int n = nums.size();
        int total_digit_count = 0;
        vector<int> digitCounts = vector<int>(n, 0);

        int cur;
        for (int i = 0; i < n; i++){
            cur = nums[i];
            while (cur > 0){
                cur = cur/10;
                total_digit_count++;
                digitCounts[i]++;
            }
        }

        vector<int> res = vector<int>(total_digit_count, 0);
        int localDigitCount;
        total_digit_count = 0;
        for (int i = 0; i < n; i++){
            localDigitCount = digitCounts[i] - 1;
            cur = nums[i];
            while (cur > 0){
                res[total_digit_count + localDigitCount] = cur % 10;
                cur = cur/10;
                localDigitCount--;
            }

            total_digit_count += digitCounts[i];
        }
        return res;
    }
};