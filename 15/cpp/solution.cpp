#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int>& nums, int target, int start, int end){
    int current_idx;
    while (end > start){
        current_idx = (end + start) / 2;
        if (nums[current_idx] == target){
            return true;
        }
        else if (nums[current_idx] < target){
            start = current_idx + 1;
            continue;
        }
        else {
            end = current_idx;
        }
    }
    return nums.size() > start ? (nums[start] == target) : false;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> solution(0);

        int previous_i = nums[0] - 1;
        int previous_j = previous_i;

        for (int i = 0; i < nums.size()-2; i++){
            if (nums [i] > 0){
                break;
            }
            if (nums[i] == previous_i){ // Dont double
                continue;
            }

            for (int j = i+1; j < nums.size()-1; j++){
                if (nums[j] == previous_j){
                    continue;
                }
                if (binarySearch(nums, -nums[i] - nums[j],j+1, nums.size() - 1)){
                    solution.push_back({nums[i], nums[j], -nums[i] - nums[j]});
                }
                previous_j = nums[j];
            }
            previous_i = nums[i];
        }
        return solution;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};

    Solution solver = Solution();
    solver.threeSum(nums);
}