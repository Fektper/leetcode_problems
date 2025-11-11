#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        auto dp = vector<vector<vector<int>>>(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        
        // Init for 0
        int count_0 = 0;
        int count_1 = 0;

        for (char c: strs[0]){
            if (c == '0'){
                count_0++;
            } else{
                count_1++;
            }
        }

        for (int c_m = 0; c_m <= m; c_m++){
            for (int c_n = 0; c_n <= n; c_n++){
                if (c_m >= count_0 && c_n >= count_1){
                    dp[0][c_m][c_n] = 1;
                } else{
                    dp[0][c_m][c_n] = 0;
                }
            }
        }

        for (int i = 1; i < strs.size(); i++){
            count_0 = 0;
            count_1 = 0;
            for (char c: strs[i]){
                if (c == '0'){
                    count_0++;
                } else {
                    count_1++;
                }
            }

            for (int c_m = 0; c_m <= m; c_m++){
                for (int c_n = 0; c_n <= n; c_n++){
                    if (c_m >= count_0 && c_n >= count_1){
                        dp[i][c_m][c_n] = max(dp[i-1][c_m][c_n], dp[i-1][c_m - count_0][c_n - count_1] +1);
                    } else {
                        dp[i][c_m][c_n] = dp[i-1][c_m][c_n];
                    }
                }
            }
        }

        return dp[strs.size()-1][m][n];

    }
};

int main(){
    vector<string> strs = {"10","0001","111001","1","0"};
    Solution solver = Solution();

    solver.findMaxForm(strs, 5, 3);
}