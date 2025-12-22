#include <vector>
#include <string>

using namespace std;




class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<bool> to_delete(100, false);

        bool change = true;
        int max_index;
        while (change){
            change = false;
            for (int i = 0; i < strs.size() - 1; i++){
                max_index = min(strs[i].size(), strs[i+1].size());
                for (int j = 0; j < max_index; j++){
                    if (to_delete[j]){
                        continue;
                    }
                    if (strs[i][j] < strs[i+1][j]){
                        break;
                    }
                    else if (strs[i][j] > strs[i+1][j]){
                        if (!to_delete[j]){
                            change = true;
                        }
                        to_delete[j] = true;
                    }
                }
            }
        }
        int res = 0;
        for (bool c: to_delete){
            res += c;
        }
        return res;
    }
};