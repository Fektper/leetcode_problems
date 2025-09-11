#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowl(char c){
    if (c > 90){
        c = c - 32;
    }
    for (char check: {'A', 'E', 'I', 'O', 'U'}){
        if (c==check){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    string sortVowels(string s) {
        vector<int> positions(0);
        vector<char> chars(0);

        for (int i = 0; i < s.size(); i++){
            if (isVowl(s[i])){
                positions.push_back(i);
                chars.push_back(s[i]);
            }
        }
        std::sort(chars.begin(), chars.end());

        for (int i = 0; i < positions.size(); i++){
            s[positions[i]] = chars[i];
        }
        return s;
    }
};

int main(){
    string test_input = "lEetcOde";
    string target_result = "lEOtcede";
    Solution solver = Solution();

    string res = solver.sortVowels(test_input);
    if (res == target_result){
        printf("Test passed!\n");
    }
    else {
        printf("Test failed!\n");
    }
}