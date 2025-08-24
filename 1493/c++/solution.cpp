#include <vector>
#include <stdio.h>

using namespace std;

int max_vector_element(vector<int>& nums){
    if (nums.size() == 0){
        return 0;
    }
    int max = nums.at(0);
    for (int i: nums){
        if (i > max){
            max = i;
        }
    }
    return max;
}

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        vector<int> lengths(0);
        vector<int> starts(0);

        int idx = 0;
        int current_length = 0;

        while (idx < nums.size()){
            while (idx < nums.size() && nums.at(idx) != 1){
                idx++;
            }
            current_length = 0;
            while (idx + current_length < nums.size() && nums.at(idx + current_length) == 1){
                current_length++;
            }
            lengths.push_back(current_length);
            starts.push_back(idx);
            idx += current_length;
        }

        if (lengths.size() == 0){
            return 0;
        }
        if (lengths.at(0) == nums.size()){
            return lengths.at(0) - 1;
        }
        if (lengths.size() == 1){
            return lengths.at(0);
        }

        vector<int> double_lengths(0);

        for (int i = 0; i < lengths.size() - 1; i++){
            if (lengths.at(i) + starts.at(i) + 1 == starts.at(i+1)){
                double_lengths.push_back(lengths.at(i) + lengths.at(i+1));
            }
        }

        return std::max(max_vector_element(lengths), max_vector_element(double_lengths));
    }
};

int main(){
    int target_sol = 5;
    vector<int> test_in = {0,1,1,1,0,1,1,0,1};
    
    Solution* solver = new Solution();
    int res = solver->longestSubarray(test_in);

    if (res == target_sol){
        printf("Test passed!\n");
    }
    else{
        printf("Test failed! Expected %d but got %d\n", target_sol, res);
    }
}