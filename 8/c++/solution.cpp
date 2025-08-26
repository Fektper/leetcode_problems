#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

bool isDigit(char c){
    return c - '0' >= 0 && c - '9' <= 0;
}

int32_t getDigit(char c){
    return c - '0'; // Assumes valid digit char
}


class Solution{
    public:
    int32_t myAtoi(string s){
        vector<int32_t> valid_digits(0);
        int32_t sign = 1;

        int32_t idx = 0;

        while (idx < s.size() && s[idx] == ' '){
            idx++;
        }
        if (idx == s.size()){
            return 0;
        }
        else if (s[idx] == '+'){
            sign = 1;
            idx++;
        }
        else if (s[idx] == '-'){
            sign = -1;
            idx++;
        }
        else if(!isDigit(s[idx])){
            return 0;
        }

        // We have sign, next char is definetly a digit, we are not at end
        // Skip leading zeros
        while (idx < s.size() && isDigit(s[idx]) && getDigit(s[idx]) == 0){
            idx++;
        }
        // Read digits till end or till invalid digit
        while (idx < s.size() && isDigit(s[idx])){
            valid_digits.push_back(getDigit(s[idx]));
            idx++;
        }

        if (valid_digits.size() > 10){
            return sign == 1 ? INT32_MAX : INT32_MIN;
        }

        int32_t result = 0;
        int32_t previous_result = result;
        for (int32_t i: valid_digits){
            // Check if op causes over/underflow
            // This worked for me locally, but not on leetcode servers :(
            // previous_result = result;
            // result = result*10;
            // result += sign*i;
            
            // if (previous_result * sign > result*sign){ // Check overflow
            //     return sign == 1 ? INT32_MAX : INT32_MIN;
            // }

            if (sign == 1){
                if (INT32_MAX  / 10 < result){
                    return INT32_MAX;
                }
                result = result*10;
                if (INT32_MAX - i < result){
                    return INT32_MAX;
                }
                result += i;
            }
            else {
                if (INT32_MIN  / 10 > result){ // according to c++11 this should be truncated toward zero
                    return INT32_MIN;
                }
                result = result*10;
                if (INT32_MIN + i > result){
                    return INT32_MIN;
                }
                result -= i;
            }
        }
        return result;
    };
};


int32_t main(){
    string test_input = "-2147483649";
    int32_t target_result = -43;

    Solution solver = Solution();
    int32_t test_result = solver.myAtoi(test_input);

    if (test_result == target_result){
        printf("Test passed\n");
    }
    else{
        printf("Test failed! Expected %d but got %d\n", target_result, test_result);
    }
}