#include <vector>

using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int min_element = __INT32_MAX__;

        int e;
        for (int num: nums){
            e = 0;
            while (num > 0){
                e += num%10;
                num = num/10;
            }
            min_element = min(min_element, e);
        }
        return min_element;
    }
};