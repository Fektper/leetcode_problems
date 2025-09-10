#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool contains(vector<int>& arr, int val){
    for (int ele: arr){
        if (val == ele){
            return true;
        }
    }
    return false;
}

bool shareLanguage(int a, int b, vector<vector<int>>& languages){
    int i = 0; int j = 0;
    int l1; int l2;
    while (i < languages[a].size() && j < languages[b].size()){
        l1 = languages[a][i];
        l2 = languages[b][j];
        if (l1 == l2){
            return true;
        }
        else if (l1 < l2){
            i++;
        }
        else {
            j++;
        }
    }
    return false;
    // for (int langA: languages[a]){
    //     for (int langB: languages[b]){
    //         if (langA == langB){
    //             return true;
    //         }
    //     }
    // }
    // return false;
}

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int maxFriend = languages.size();
        vector<vector<int>> friendGroups(maxFriend);
        for (int i = 0; i < maxFriend; i++){
            std::sort(languages[i].begin(), languages[i].end());
        }
        for (vector<int> friendship: friendships){
            int f1 = friendship[0]-1;
            int f2 = friendship[1]-1;
            // Optimisable with hashmap!
            if (!contains(friendGroups[f1], f2)){
                friendGroups[f1].push_back(f2);
            }
            if (!contains(friendGroups[f2], f1)){
                friendGroups[f2].push_back(f1);
            }
        }

        // for (int i = 0; i < friendGroups.size(); i++){
        //     std::sort(friendGroups[i].begin(), friendGroups[i].end());
        // }

        int minTeaching = __INT32_MAX__;
        int thisMinTeaching = 0;
        bool hasLearned[maxFriend];
        for (int langIdx = 0; langIdx < n; langIdx++){
            std::fill(hasLearned, hasLearned+maxFriend, false);
            
            for (int pIdx = 0; pIdx < maxFriend; pIdx++){
                if (contains(languages[pIdx], langIdx+1) || hasLearned[pIdx]){
                    continue;
                }
                for (int fIdx: friendGroups[pIdx]){
                    if (!shareLanguage(pIdx, fIdx, languages)){
                        hasLearned[pIdx] = contains(languages[pIdx], langIdx+1) ? false : true;
                        hasLearned[fIdx] = contains(languages[fIdx], langIdx+1) ? false : true;
                    }
                }
            }
            minTeaching = std::min(minTeaching, (int) count(hasLearned, hasLearned+maxFriend, true));
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