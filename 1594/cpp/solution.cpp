#include <vector>
#include <algorithm>

using namespace std;

#define MOD_VAL (((long long int)1e9) + 7)

struct CellValues{
    long long int max;
    long long int min;
};


class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<CellValues>> res_grid = vector<vector<CellValues>>(rows, vector<CellValues>(cols, {0, 0}));
        
        // Init top left value
        long long int v = grid[0][0];
        res_grid[0][0] = {v, v};

        // Init top row
        for (int col = 1; col < cols; col++){
            v = grid[0][col];
            long long int prev_v = res_grid[0][col-1].max;
            res_grid[0][col] = {v*prev_v, v*prev_v};
        }
        // Init left col
        for (int row = 1; row < rows; row++){
            v = grid[row][0];
            long long int prev_v = res_grid[row-1][0].max;
            res_grid[row][0] = {v*prev_v, v*prev_v};
        }
        
        long long int l_max, l_min, t_max, t_min; 
        long long int vt;
        for (int row = 1; row < rows; row++){
            for (int col = 1; col < cols; col++){
                l_max = res_grid[row][col-1].max;
                l_min = res_grid[row][col-1].min;
                t_max = res_grid[row-1][col].max;
                t_min = res_grid[row-1][col].min;
                v = grid[row][col];
                res_grid[row][col] = {max({v*l_max, v*l_min, v*t_max, v*t_min}), min({v*l_max, v*l_min, v*t_max, v*t_min})};
            }
        }

        CellValues r = res_grid[rows-1][cols-1];
        if (r.max < 0){
            return -1;
        }

        return (r.max % MOD_VAL);
    }
};