#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a; int b; int c;
        for (int i = nums.size()-3; i >= 0; i--){
            a = nums[i];
            b = nums[i+1];
            c = nums[i+2];
            if (a+b > c){
                return a+b+c;
            }
        }
        return 0;
    }
};