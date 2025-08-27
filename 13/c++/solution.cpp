#include <stdio.h>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> digit_values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int romanToInt(string s) {
        int res = 0;
        int idx = 0;
        while (idx < s.size() - 1){
            if (digit_values[s[idx+1]] <= digit_values[s[idx]]){
                res += digit_values[s[idx]];
                idx++;
            }
            else{
                res += digit_values[s[idx+1]];
                res -= digit_values[s[idx]];
                idx += 2;
            }
        }
        if (idx < s.size()){
            res += digit_values[s[idx]];
        }
        return res;
    }
};



int main(){
    string test_input = "III";
    int target_out = 3;

    Solution solver = Solution();
    int res = solver.romanToInt(test_input);

    if (res == target_out){
        printf("Test passed\n");
    }
    else {
        printf("Test failed! Expected %d, but got %d\n", target_out, res);
    }
    }