#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

struct Sol{
    int size;
    int rem_0;
    int rem_1;

    bool operator==(const Sol& other) const{
        return size == other.size && rem_0 == other.rem_0 && rem_1 == other.rem_1;
    }
};


class SolHash{
    public:
    size_t operator() (const Sol& a) const{
        return a.size + a.rem_1 * 1000 + a.rem_0 * 1000000;
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> counts(strs.size());
        int c_0; int c_1;
        // Count 0's and 1's in each string
        for (int i = 0; i < strs.size(); i++){
            string s = strs[i];
            c_0 = 0; c_1 = 0;
            for (char c: s){
                if (c=='0'){
                    c_0++;
                }
                if (c=='1'){
                    c_1++;
                }
            }
            counts[i] = {c_0, c_1};
        }

        auto dp = vector<unordered_set<Sol, SolHash>>(strs.size());
        // First is set size
        // Second is array of possible solutions
        // Third is individual solution: set size, remaining 0's, remaining 1's
        // Each entry is valid!

        // Init first entry
        if (counts[0][0] <= m && counts[0][1] <= n){
            dp[0] = {{0, m, n}, {1, m-counts[0][0], n - counts[0][1]}};
        } else {
            dp[0] = {{0, m, n}};
        }
        

        for (int i = 1; i < counts.size(); i++){
            dp[i] = {};
            for (Sol sol: dp[i-1]){
                if (sol.rem_0 >= counts[i][0] && sol.rem_1 >= counts[i][1]){
                    dp[i].insert({sol.size + 1, sol.rem_0 - counts[i][0], sol.rem_1 - counts[i][1]});
                }
                dp[i].insert(sol);
            }
        }

        // Find best of final sol
        int res = 0;
        for (auto sol: dp[counts.size() - 1]){
            if (sol.size > res){
                res = sol.size;
            }
        }
        return res;

    }
};

int main(){
    vector<string> strs = {"10","0001","111001","1","0"};
    Solution solver = Solution();

    solver.findMaxForm(strs, 5, 3);
}