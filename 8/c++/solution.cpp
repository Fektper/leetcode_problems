#include <string>
#include <stdio.h>

using namespace std;

bool isDigit(char c){
    if (c >= 48 && c <= 57){
        return true;
    }
    return false;
}

int getDigit(char c){ // Required that c is valid digit
    return (int)(c - 48);
}

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        string valid_chars = "";
        int start_index = 0;
        while(start_index < s.size() && s[start_index] == ' '){
            start_index++;
        }
        if (start_index == s.size()){
            return 0;
        }
        if (s[start_index] == '+'){
            sign = 1;
        } else if (s[start_index] == '-'){
            sign = -1;
        } else if (!isDigit(s[start_index])){
            return 0;
        }
        return 5;
    }
};


int main(){
    string test_input = "   -000043 hello world";
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