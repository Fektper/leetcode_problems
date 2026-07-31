#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frequency = vector<int>(26, 0);
        for (char c: word){
            frequency[c-'a'] += 1;
        }
        sort(frequency.begin(), frequency.end(), std::greater<>());
        int res = 0;
        for (int i = 0; i < 26; i++){
            int mul = (i / 8) + 1;
            res += mul*frequency[i];
        }
        return res;
    }
};