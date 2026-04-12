#include <vector>
#include <string>

#define MAXLEN 27000

using namespace std;

int dist(int prev, int cur){
    int x1 = prev % 6;
    int y1 = prev / 6;

    int x2 = cur % 6;
    int y2 = cur / 6;
    return abs(x1-x2) + abs(y1-y2);
}

class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(26, vector<vector<int>>(26, vector<int>(n+1, MAXLEN)));

        for (int i = 0; i < 26; i++){
            for (int j = 0; j < 26; j++){
                dp[i][j][0] = 0;
            }
        }

        int c;
        for (int k = 0; k < n; k++){
            c = word[k] - 'A';
            for (int i = 0; i < 26; i++){
                for (int j = 0; j < 26; j++){
                    dp[c][j][k+1] = min(dp[c][j][k+1] ,dp[i][j][k] + dist(i, c)); // finger one moves from i to c
                    dp[i][c][k+1] = min(dp[i][c][k+1] ,dp[i][j][k] + dist(j, c)); // figner two moves from j to c
                }
            }
        }


        int last = word[n-1] - 'A';
        int res = MAXLEN;
        for (int i = 0; i < 26; i++){
            res = min(res, dp[i][last][n]);
            res = min(res, dp[last][i][n]);
        }
        return res;
    }
};

int main(){
    Solution solver = Solution();
    printf("Word has %d distance\n", solver.minimumDistance("CAKE"));
}