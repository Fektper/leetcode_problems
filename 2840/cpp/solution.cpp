#include <string>
#include <unordered_map>

using namespace std;

bool map_equal(unordered_map<char, int>& a, unordered_map<char, int>& b){
    char key;
    int value;
    for (auto it: a){
        key = it.first;
        value = it.second;
        if (b.find(key) == b.end()){
            return false;
        }
        else if (b[key] != value){
            return false;
        }
    }
    for (auto it: b){
        key = it.first;
        value = it.second;
        if (a.find(key) == a.end()){
            return false;
        }
        else if (a[key] != value){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();

        unordered_map<char, int> s1_even;
        unordered_map<char, int> s1_odd;
        unordered_map<char, int> s2_even;
        unordered_map<char, int> s2_odd;

        char c1;
        char c2;
        for (int i = 0; i < n; i+=2){
            c1 = s1[i];
            c2 = s2[i];
            if (s1_even.find(c1) == s1_even.end()){
                s1_even.insert({c1, 1});
            } else {
                s1_even[c1] = s1_even[c1] + 1;
            }

            if (s2_even.find(c2) == s2_even.end()){
                s2_even.insert({c2, 1});
            } else {
                s2_even[c2] = s2_even[c2] + 1;
            }
        }

        for (int i = 1; i < n; i+=2){
            c1 = s1[i];
            c2 = s2[i];
            if (s1_odd.find(c1) == s1_odd.end()){
                s1_odd.insert({c1, 1});
            } else {
                s1_odd[c1] = s1_odd[c1] + 1;
            }

            if (s2_odd.find(c2) == s2_odd.end()){
                s2_odd.insert({c2, 1});
            } else {
                s2_odd[c2] = s2_odd[c2] + 1;
            }
        }

        return map_equal(s1_even, s2_even) && map_equal(s1_odd, s2_odd);
    }
};