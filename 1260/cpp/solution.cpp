#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> res = vector<vector<int>>(rows, vector<int>(cols, 0));

        int pos; int i_new; int j_new;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                pos = i * cols + j + k;
                i_new = (pos / cols) % rows;
                j_new = pos%cols;
                res[i_new][j_new] = grid[i][j];
            }
        }

        return res;

    }
};