#include <vector>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maximum = 0;
        int minimum = __INT32_MAX__;

        for (int num: nums){
            if (num > maximum){
                maximum = num;
            }
            if (num < minimum){
                minimum = num;
            }
        }
        long long int dif = maximum - minimum;

        return k * dif;
    }
};