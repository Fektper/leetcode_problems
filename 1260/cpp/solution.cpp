#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> res = vector<vector<int>>(rows, vector<int>(cols, 0));

        int delta_row; int j_new;
        for (int j = 0; j < cols; j++){
            delta_row = (j+k) / cols;
            j_new = (j + k) % cols;
            for (int i = 0; i < rows; i++){
                res[(i + delta_row) % rows][j_new] = grid[i][j];
            }
        }
        return res;

    }
};