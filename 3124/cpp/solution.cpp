#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool lowerAppeared[26];
        std::fill_n(lowerAppeared, 26, false);
        bool upperAppeared[26];
        std::fill_n(upperAppeared, 26, false);

        for (char c: word){
            if (c <= 'Z'){
                upperAppeared[c-'A'] = true;
            }
            else {
                if (upperAppeared[c-'a']){
                    lowerAppeared[c-'a'] = false;
                }
                else {
                    lowerAppeared[c-'a'] = true;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 26; i++){
            if (upperAppeared[i] && lowerAppeared[i]){
                res++;
            }
        }
        return res;
    }
};