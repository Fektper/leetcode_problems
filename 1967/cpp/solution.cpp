#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        int n = word.size();
        for (string pattern: patterns){
            bool has_word = false;
            int m = pattern.size();
            for (int i = 0; i < n - m + 1; i++){
                has_word = true;
                for (int j = 0; j < m; j++){
                    if (pattern[j] != word[i + j]){
                        has_word = false;
                        break;
                    }
                }
                if (has_word){
                    break;
                }
            }

            if (has_word){
                res++;
            }
        }

        return res;
    }
};