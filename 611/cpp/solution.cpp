#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // unordered_map<int, int> lastValidIndex;
        int resCount = 0;

        int left; int right;
        for (int i = nums.size()-1; i > 1; i--){
            left = 0;
            right = i-1;

            while (right > left){
                if (nums[left] + nums[right] > nums[i]){
                    resCount += right-left;
                    right--;
                }
                else {
                    left++;
                }
            }
        }

        return resCount;
    }
};

int main(){
    Solution solver = Solution();
    vector<int> test = {2, 2, 3, 4};
    solver.triangleNumber(test);
    test = {1};
    solver.triangleNumber(test);
    test = {0};
    solver.triangleNumber(test);
}