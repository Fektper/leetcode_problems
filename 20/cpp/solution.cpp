#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2){
            return false;
        }
        stack<char, vector<char>> next_expect;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                next_expect.push(')');
                continue;
            } else if (s[i] == '[' || s[i] == '{'){
                next_expect.push(s[i]+2);
            }
            else{
                if (next_expect.empty() || s[i] != next_expect.top()){
                    return false;
                }
                next_expect.pop();
            }
        }
        return next_expect.empty();
    }
};