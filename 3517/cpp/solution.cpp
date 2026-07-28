#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int char_counts[26] = {};
        int n = s.size();

        string res(n, 'a');
        if (n % 2 == 1){
            res[n/2] = s[n/2];
        }

        for (int i = 0; i < n/2; i++){
            char_counts[s[i] - 'a']++;
        }

        int i = 0;
        int j = 0;
        while (i < n/2){
            if (char_counts[j] == 0){
                j++;
                continue;
            }
            res[i] = 'a' + j;
            res[n-i-1] = 'a' + j;
            char_counts[j]--;
            i++;
        }
        
        return res;
    }
};