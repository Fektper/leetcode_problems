#include <vector>
#include <unordered_map>
#include <string>


using namespace std;

bool isAnagram(string& a, string& b){
    if (a.size() != b.size()){
        return false;
    }

    unordered_map<char, int> a_counts;
    unordered_map<char, int> b_counts;
    for (char ac: a){
        if (a_counts.find(ac) != a_counts.end()){
            a_counts[ac] += 1;
        }
        else {
            a_counts[ac] = 1;
        }
    }
    for (char bc: b){
        if (b_counts.find(bc) != b_counts.end()){
            b_counts[bc] += 1;
        }
        else {
            b_counts[bc] = 1;
        }
    }

    for (auto it = a_counts.begin(); it != a_counts.end(); it=next(it)){
        if (b_counts.find(it->first) == b_counts.end() || b_counts[it->first] != it->second){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int i = 1;

        while (i < words.size()){
            if (isAnagram(words[i], words[i-1])){
                words.erase(words.begin() + i);
                i = max(i-1, 1);
            }
            else{
                i++;
            }
        }
        return words;
    }
};