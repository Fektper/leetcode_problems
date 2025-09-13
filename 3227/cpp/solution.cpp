#include <string>

using namespace std;

bool isVowl(char c){
    if (c > 91){
        c = c - 32;
    }
    if (c == 'A' || c == 'E' || c == 'I' || c=='O' || c == 'U'){
        return true;
    }
    return false;
}

class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c: s){
            if (isVowl(c)){
                return true;
            }
        }
        return false;
    }
};