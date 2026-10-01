#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }

        stack<char> next_parenthesis = stack<char>();

        for (char c: s) {
            if (c == '(') {
                next_parenthesis.push(')');
            }
            else if ( c == '{') {
                next_parenthesis.push('}');
            }
            else if (c == '[') {
                next_parenthesis.push(']');
            }
            else {
                if (next_parenthesis.size() > 0){
                    char same = next_parenthesis.top();
                    next_parenthesis.pop();
                    if (same != c) {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }

        return next_parenthesis.size() == 0;
    }
};

int main() {
    string test = "()[]{}";
    Solution sol = Solution();
    sol.isValid(test);
}