#include <vector>
#define MOD_VAL 12345


using namespace std;

int pos_mod(int v, int n){
    return ((v%n) + n) % n;
}

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<long long int>> prefix_prod = vector<vector<long long int>>(rows, vector<long long int>(cols, 0));
        vector<vector<long long int>> suffix_prod = vector<vector<long long int>>(rows, vector<long long int>(cols, 0));

        prefix_prod[0][0] = 1;
        suffix_prod[rows-1][cols-1] = 1;

        int r, c;
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (col == 0){
                    if (row == 0){
                        continue;
                    }
                    r = row-1;
                    c = cols-1;
                }
                else {
                    r = row;
                    c = col-1;
                }

                prefix_prod[row][col] = (prefix_prod[r][c] * grid[r][c]) % MOD_VAL;
            }
        }

        for (int row = rows-1; row >= 0; row--){
            for (int col = cols-1; col >= 0; col--){
                if (col == cols-1){
                    if (row == rows-1){
                        continue;
                    }
                    c = 0;
                    r = row+1;
                }
                else {
                    r = row;
                    c = col+1;
                }

                suffix_prod[row][col] = (suffix_prod[r][c] * grid[r][c]) % MOD_VAL;
            }
        }

        vector<vector<int>> res = vector<vector<int>>(rows, vector<int>(cols, 0));

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                res[row][col] = (prefix_prod[row][col] * suffix_prod[row][col]) % MOD_VAL;
            }
        }

        return res;

    }
};