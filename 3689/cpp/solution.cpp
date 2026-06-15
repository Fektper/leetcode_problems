#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maximum = *max_element(nums.begin(), nums.end());
        int minimum = *min_element(nums.begin(), nums.end());

        long long int dif = maximum - minimum;

        return k * dif;
    }
};