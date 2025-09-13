#include <string>
#include <map>
#include <unordered_map>

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
        unordered_map<char, int> consonant_counts;
        unordered_map<char, int> vowel_counts;

        for (char c: s){
            if (isVowl(c)){
                auto a = vowel_counts.find(c);
                if (a == vowel_counts.end()){
                    vowel_counts.insert({c, 1});
                } else{
                    a->second = a->second + 1;
                }
            }

            else{
                auto a = consonant_counts.find(c);
                if (a == consonant_counts.end()){
                    consonant_counts.insert({c, 1});
                } else{
                    a->second = a->second + 1;
                }
            }
        }
        int vowelMax = 0;
        int consonantMax = 0;
        for (auto cons: consonant_counts){
            consonantMax = std::max(consonantMax, cons.second);
        }
        for (auto vowels: vowel_counts){
            vowelMax = std::max(vowelMax, vowels.second);
        }
        return consonantMax + vowelMax;
    }
};