#include <string>

using namespace std;


class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26];
        std::fill(broken, broken+26*sizeof(char), false);
        for (char c: brokenLetters){
            broken[c - 'a'] = true;
        }

        int wordCount = 0;
        bool writeAble = true;
        for (int i = 0; i < text.size(); i++){
            if (text[i] == ' '){
                if (writeAble){
                    wordCount++;
                }
                writeAble = true;
                continue;
            }
            if (broken[text[i]-'a']){
                writeAble = false;
            }
        }

        if (writeAble){
            wordCount++;
        }
        return wordCount;
    }
};