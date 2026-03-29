#include <string>

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1 == s2){
            return true;
        }
        for (int i = 0; i < s1.size(); i++){
            if (s1[i] != s2[i]){
                int j = i+2 > s1.size() ? i-2 : i+2;
                char tmp = s1[i];
                s1[i] = s1[j];
                s1[j] = tmp;
            }
        }
        return s1==s2;

    }
};