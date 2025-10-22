#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        unordered_set<long long int> candidate_numbers;
        for (int num: nums){
            candidate_numbers.insert(num-k);
            candidate_numbers.insert(num);
            candidate_numbers.insert(num+k);
        }

        int max_freq = 0;

        auto candidate_iterator = candidate_numbers.begin();
        upper_bound(nums.begin(), nums.end(), 5);
        int this_count;
        int in_range_count;
        while (candidate_iterator != candidate_numbers.end()){

            in_range_count = distance(lower_bound(nums.begin(), nums.end(), *candidate_iterator - k), 
                                    upper_bound(nums.begin(), nums.end(), *candidate_iterator + k));
            this_count = distance(lower_bound(nums.begin(), nums.end(), *candidate_iterator),
                                    upper_bound(nums.begin(), nums.end(), *candidate_iterator));

            max_freq = max(max_freq, min(in_range_count - this_count, numOperations) + this_count);
            candidate_iterator = next(candidate_iterator);
        }


        return max_freq;
    }
};

int main(){
    vector<int> inpt = {15,113,122,102};
    Solution solver = Solution();

    solver.maxFrequency(inpt, 90, 3);
}