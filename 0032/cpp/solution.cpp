#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        stack<int> lastInvalid;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                lastInvalid.push(i);
            }
            else {
                if (lastInvalid.size() > 0) {
                    int j = lastInvalid.top();
                    if (s[j] == '('){
                        lastInvalid.pop();
                        if (lastInvalid.size() > 0) {
                            longest = max(longest, i - lastInvalid.top());
                        }
                        else {
                            longest = max(longest, i+1);
                        }
                        
                    }
                    else {
                        longest = max(longest, i-1 - j);
                        lastInvalid.push(i);
                    }
                }
                else {
                    lastInvalid.push(i);
                    longest = max(longest, i);
                }
            }
        }

        return longest;

    }
};

/*
"()(()"
"((("
")))"
"()()()"
"(()()())()()))()()(((()))))"
""
"()(()()"
"())()()((()()()))()()()()()()())))(()(())))()())()()()())(((()))))()()())()()()()())))("


*/