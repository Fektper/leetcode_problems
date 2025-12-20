#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int res = 0;
        for (int col = 0; col < m; col++){
            for (int i = 1; i < n; i++){
                if (strs[i][col] < strs[i-1][col]){
                    res++;
                    break;
                }
            }
        
        }

        return res;
    }
};