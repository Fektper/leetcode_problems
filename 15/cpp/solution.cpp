#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> solution(0);

        int previous_i = nums[0] - 1;
        int previous_j = previous_i;

        int j; int k; int target;

        for (int i = 0; i < nums.size()-2; i++){
            if (nums [i] > 0){
                break;
            }
            if (nums[i] == previous_i){ // Dont double
                continue;
            }

            j = i+1;
            k = nums.size() - 1;
            target = -nums[i];
            previous_j = previous_i;
            while(k > j){
                if (nums[j] == previous_j){
                    j++;
                    continue;
                }
                
                if (nums[j] + nums[k] == target){
                    solution.push_back({nums[i], nums[j], nums[k]});
                    previous_j = nums[j];
                    j++;
                    k--;
                    continue;
                }
                else if(nums[j] + nums[k] < target){
                    j++;
                    continue;
                }
                else{
                    k--;
                    continue;
                }
            }
            previous_i = nums[i];
        }
        return solution;
    }
};

int main(){
    vector<int> nums = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};

    Solution solver = Solution();
    solver.threeSum(nums);
}