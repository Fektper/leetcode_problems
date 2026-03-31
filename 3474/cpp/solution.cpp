#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>

using namespace std;

bool SubStringMatches(string& orig, string& pattern, int pos){
    for (int i = 0; i < pattern.size(); i++){
        if (orig[pos+i] != pattern[i]){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string res = string(n + m - 1, 'a');
        vector<bool> locked = vector<bool>(n+m+1, false);

        char c; // Handle T, so that string matches
        for (int i = 0; i < n; i++){
            if (str1[i] == 'T'){
                for (int j = 0; j < m; j++){
                    c = str2[j];
                    if (locked[i+j] && res[i+j] != c){
                        return "";
                    }
                    res[i+j] = str2[j];
                    locked[i+j] = true;
                }
            }
        }

        // Handle not matching 'F'
        bool passed;
        for (int i = 0; i < n; i++){
            if (str1[i] == 'F'){
                // String is not allowed to match!
                if(SubStringMatches(res, str2, i)){
                    passed = false;
                    for (int j = m-1; j >= 0; j--){
                        if (!locked[i+j] && res[i+j] < 'z'){
                            res[i+j] += 1;
                            passed = true;
                            break;
                        }
                    }
                    if (!passed){
                        return "";
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution solver = Solution();
    string str1 = "TFTF";
    string str2 = "ab";
    std::cout << solver.generateString(str1, str2) << "\n";
}