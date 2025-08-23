#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        if (x == 0){
            return true;
        }

        int digits[32];
        int total_digit_count = 0;

        while (x > 0){
            digits[total_digit_count] = x % 10;
            x = x /10;
            total_digit_count++;
        }

        for (int i = 0; i < total_digit_count / 2; i++){
            if (digits[i] != digits[total_digit_count - 1 - i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    int test_input = 121;
    bool wanted_result = true;

    Solution* solver = new Solution();

    if (solver->isPalindrome(test_input) == wanted_result){
        printf("Test passed\n");
    }
    else{
        printf("Test failed\n");
    }
}