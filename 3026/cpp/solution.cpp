#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long int running_sum = 0;
        unordered_map<int, long long int> min_running_sums;

        unordered_map<int, long long int>::iterator map_search_result;
        int lower; int higher;
        long long int max_sum = -__LONG_LONG_MAX__;
        long long int current_val;

        for (int i = 0; i < n; i++){
            map_search_result = min_running_sums.find(nums[i]);
            if (map_search_result == min_running_sums.end()){
                // Not in map
                min_running_sums.insert({nums[i], running_sum});
            }
            else {
                if (map_search_result->second > running_sum){
                    map_search_result->second = running_sum;
                }
            }
            running_sum += nums[i];

            lower = nums[i] - k;
            higher = nums[i] + k;

            map_search_result = min_running_sums.find(lower);
            if (map_search_result != min_running_sums.end()){
                current_val = running_sum - map_search_result->second;
                if (current_val > max_sum){
                    max_sum = current_val;
                }
            }
            map_search_result = min_running_sums.find(higher);
            if (map_search_result != min_running_sums.end()){
                current_val = running_sum - map_search_result->second;
                if (current_val > max_sum){
                    max_sum = current_val;
                }
            }
        }
        return max_sum == -__LONG_LONG_MAX__ ? 0 : max_sum;
        
    }
};