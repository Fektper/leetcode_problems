#include <string>

using namespace std;

bool isVowl(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c=='o' || c == 'u'){
        return true;
    }
    return false;
}

class Solution {
public:
    int maxFreqSum(string s) {
        int counts[26];
        std::fill(counts, counts+sizeof(char)*26, 0);

        for (char c: s){
            counts[c-97]++;
        }
        int vowelMax = 0;
        int consonantMax = 0;

        for (int i = 0; i < 26; i++){
            if (isVowl(i+97)){
                vowelMax = std::max(vowelMax, counts[i]);
            }
            else{
                consonantMax = std::max(consonantMax, counts[i]);
            }
        }
        return consonantMax + vowelMax;
    }
};