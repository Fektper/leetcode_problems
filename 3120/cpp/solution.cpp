#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> small = vector<int>(26, 0);
        vector<int> big = vector<int>(26, 0);

        for (char c: word){
            if (c <= 'Z'){
                big[c-'A']++;
            }
            else{
                small[c-'a']++;
            }
        }

        int res = 0;
        for (int i = 0;i < 26; i++){
            if (small[i] > 0 && big[i] > 0){
                res++;
            }
        }
        return res;
    }
};