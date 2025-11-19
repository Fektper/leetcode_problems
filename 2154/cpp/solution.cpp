#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());

        while(binary_search(nums.begin(), nums.end(), original)){
            original = original << 1;
        }
        return original;
    }
};