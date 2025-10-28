#include <vector>

using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int res_count = 0;

        int left = 0;
        int right = 0;
        for (int num: nums){
            right += num;
        }

        for (int i = 0; i < nums.size(); i++){

            if (nums[i] == 0){
                if (left == right){
                    res_count += 2;
                }
                else if (left -1 == right || right -1 == left)
                {
                    res_count++;
                }
                
            }
            left += nums[i];
            right -= nums[i];
        }

        return res_count;
    }
};

int main(){
    Solution solver = Solution();
    vector<int> test = {1, 0, 2, 0, 3};
    solver.countValidSelections(test);
}