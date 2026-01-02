#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> map = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        int res_count = 1;

        for (char d: digits){
            res_count *= map[d].size();
        }

        vector<string> res = vector<string>(res_count, string(digits.size(), ' '));
        int divider = 1;
        int counter = 0;
        int digit_index = 0;
        for (int i = 0; i < digits.size(); i++){
            counter = 0;
            digit_index = 0;

            for (int j = 0; j < res_count; j++){
                if (counter >= divider){
                    digit_index = (digit_index + 1) % map[digits[i]].size();
                    counter = 0;
                }
                res[j][i] = map[digits[i]][digit_index];
                counter++;
            }

            divider *= map[digits[i]].size();
        }

        return res;
    }
};

int main(){
    string test = "9387";
    Solution solver  = Solution();
    solver.letterCombinations(test);
}