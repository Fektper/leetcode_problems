#include <vector>
#include <stdio.h>
#include <unordered_set>

using namespace std;

bool shareLanguage(unordered_set<int>& l1s, unordered_set<int>& l2s){
    for (int l1: l1s){
        if (l2s.find(l1) != l2s.end()){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        vector<unordered_set<int>> languageSet(languages.size());

        for (int i = 0; i < languages.size(); i++){
            for (int lang: languages[i]){
                languageSet[i].insert(lang-1);
            }
        }

        unordered_set<int> problems;
        int f1; int f2;
        for (vector<int> friendship: friendships){
            f1 = friendship[0]-1;
            f2 = friendship[1]-1;
            if (!shareLanguage(languageSet[f1], languageSet[f2])){
                problems.insert(f1);
                problems.insert(f2);
            }
        }

        int minCount = __INT32_MAX__;
        int thisMinCount = 0;
        for (int langIdx = 0; langIdx < n; langIdx++){
            thisMinCount = 0;
            for (int i: problems){
                if (languageSet[i].find(langIdx) == languageSet[i].end()){
                    thisMinCount++;
                }
            }
            minCount = std::min(minCount, thisMinCount);
        }
        return minCount;
    }
};

int main(){
    Solution solver = Solution();
    int n = 2;
    vector<vector<int>> languages = {{1},{2},{1,2}};
    vector<vector<int>> friendships = {{1,2},{1,3},{2,3}};
    int target_res = 1;

    int res = solver.minimumTeachings(n, languages, friendships);

    if (res != target_res){
        printf("Test failed! Expected %d but got %d\n", target_res, res);
    }
    else{
        printf("Test passed!\n");
    }
}