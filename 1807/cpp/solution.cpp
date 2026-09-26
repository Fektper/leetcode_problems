#include <vector>
#include <string.h>
#include <unordered_map>

using namespace std;
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (vector<string> pair: knowledge){
            dict[pair[0]] = pair[1];
        }

        bool parseKey = false;
        string current_key = "";
        string res = "";
        int i = 0;
        while (i < s.size()) {
            if (s[i] != '(' && !parseKey) {
                res.push_back(s[i]);
            }
            else if (parseKey && s[i] != ')') {
                current_key.push_back(s[i]);
            }
            else if (s[i] == '('){
                parseKey = true;
            }
            else {
                
                if (dict.find(current_key) != dict.end()){
                    res.append(dict[current_key]);
                }
                else {
                    res.push_back('?');
                }
                parseKey = false;
                current_key = "";
            }
            i++;
        }
        return res;
    }
};

int main(){
    string s = "(name)is(age)yearsold";
    vector<vector<string>> knowledge = {{"name","bob"},{"age","two"}};

    Solution sol = Solution();
    sol.evaluate(s, knowledge);
}