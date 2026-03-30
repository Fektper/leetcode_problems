#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();

        vector<int> s1_even = vector<int>(26, 0);
        vector<int> s1_odd = vector<int>(26, 0);
        vector<int> s2_even = vector<int>(26, 0);
        vector<int> s2_odd = vector<int>(26, 0);

        int c1;
        int c2;
        for (int i = 0; i < n; i+=2){
            c1 = s1[i] - 'a';
            c2 = s2[i] - 'a';
            s1_even[c1]++;
            s2_even[c2]++;
        }

        for (int i = 1; i < n; i+=2){
            c1 = s1[i] - 'a';
            c2 = s2[i] - 'a';
            s1_odd[c1]++;
            s2_odd[c2]++;
        }

        for (int i = 0; i < s1_even.size(); i++){
            if (s1_even[i] != s2_even[i] || s1_odd[i] != s2_odd[i]){
                return false;
            }
        }
        return true;
    }
};