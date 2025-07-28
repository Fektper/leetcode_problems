#include <vector>
#include <stdio.h>

#define MAX_BINARY_DIGIT 16 // floor(log2(10^5))

using namespace std;
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int total_or_value = 0;
        for (int num: nums){
            total_or_value |= num;
        }

        int total_set_num = 0;
        for (int i = 1; i <= (1 << nums.size()); i++){
            int this_set_value = 0;
            for (int num_digit = 0; num_digit < nums.size(); num_digit++){
                if ((1<<num_digit) & i){
                    this_set_value |= nums.at(num_digit);
                }
            }
            if (this_set_value == total_or_value){
                total_set_num += 1;
            }
        }

        return total_set_num;
    }
};

int main(){
    std::vector<int> test_input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    Solution* sol = new Solution();
    int res = sol->countMaxOrSubsets(test_input);
    if (res == 487121){
        printf("Test passed\n");
    } else{
        printf("Test failed\n");
    }
}