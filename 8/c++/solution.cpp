#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

bool isDigit(char c){
    return c - '0' >= 0 && c - '9' <= 0;
}

int getDigit(char c){
    return c - '0'; // Assumes valid digit char
}


class Solution{
    public:
    int myAtoi(string s){
        vector<int> valid_digits(0);
        int sign = 1;

        int idx = 0;

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

        int result = 0;
        int previous_result = result;
        for (int i: valid_digits){
            previous_result = result;
            result = result*10;
            result += sign*i;

            if (previous_result * sign > result*sign){ // Check overflow
                return sign == 1 ? INT32_MAX : INT32_MIN;
            }
        }
        return result;
    };
};


int main(){
    string test_input = "-2147483649";
    int target_result = -43;

    Solution solver = Solution();
    int test_result = solver.myAtoi(test_input);

    if (test_result == target_result){
        printf("Test passed\n");
    }
    else{
        printf("Test failed! Expected %d but got %d\n", target_result, test_result);
    }
}