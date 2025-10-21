#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int current_num = nums[i];
        int max_frequency = 0;
        int this_num_count = 0;
        int candidate_count = 0;
        // vector<int>::iterator first_this;
        // ve

        while (current_num <= nums[nums.size() - 1]){

            this_num_count = distance(lower_bound(nums.begin(), nums.end(), current_num), upper_bound(nums.begin()+i, nums.end(), current_num));
            candidate_count = distance(lower_bound(nums.begin(), nums.end(), current_num-k), upper_bound(nums.begin()+i, nums.end(), current_num+k));

            candidate_count = min(candidate_count - this_num_count, numOperations);
            max_frequency = max(max_frequency, candidate_count + this_num_count);

            // Update to next num
            if (i == nums.size() - 1){
                break;
            }
            if (nums[i+1] > current_num + 2*k){
                // Next num is out of range, intermediates cant be better
                current_num = nums[i+1];
                i = i+1;
            }
            else {
                if (nums[i+1] > current_num + k){
                    // Possible intermediates better, check from lowest reachable by next higher
                    current_num = nums[i+1] - k;
                }
                else {
                    current_num++;
                    if (current_num == nums[i+1]){
                        i++;
                    }
                }
            }
        }
        return max_frequency;
    }
};

int main(){
    vector<int> inpt = {1,4,5};

    Solution solver = Solution();

    solver.maxFrequency(inpt, 1, 2);

}