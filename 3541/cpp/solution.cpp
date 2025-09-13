#include <string>

using namespace std;

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

        char c;
        for (int i = 0; i < 26; i++){
            c = i+97;
            if (c == 'a' || c == 'e' || c == 'i' || c=='o' || c == 'u'){
                vowelMax = std::max(vowelMax, counts[i]);
            }
            else{
                consonantMax = std::max(consonantMax, counts[i]);
            }
        }
        return consonantMax + vowelMax;
    }
};