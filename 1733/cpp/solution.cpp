#include <vector>
#include <algorithm>
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

        vector<unordered_set<int>> friendGroups(m);
        vector<unordered_set<int>> languageSet(languages.size());

        int f1; int f2;
        for (vector<int> friendship: friendships){
            f1 = friendship[0]-1;
            f2 = friendship[1]-1;

            friendGroups[f1].insert(f2);
            friendGroups[f2].insert(f1);
        }

        for (int i = 0; i < languages.size(); i++){
            for (int lang: languages[i]){
                languageSet[i].insert(lang-1);
            }
        }

        int minTeaching = __INT32_MAX__;
        unordered_set<int> hasLearned;

        for (int langIdx = 0; langIdx < n; langIdx++){
            hasLearned = {};

            for (int pIdx = 0; pIdx < m; pIdx++){
                if (languageSet[pIdx].find(langIdx) != languageSet[pIdx].end() || hasLearned.find(pIdx) != hasLearned.end()){
                    continue;
                }

                for (int fIdx: friendGroups[pIdx]){
                    if (!shareLanguage(languageSet[pIdx], languageSet[fIdx])){
                        hasLearned.insert(pIdx);
                        if (hasLearned.find(fIdx) != hasLearned.end()){
                            continue;
                        }
                        else if (languageSet[fIdx].find(langIdx) == languageSet[fIdx].end()){
                            hasLearned.insert(fIdx);
                        }
                    }
                }
            }
            minTeaching = std::min(minTeaching, (int) hasLearned.size());
        }
        
        return minTeaching;
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