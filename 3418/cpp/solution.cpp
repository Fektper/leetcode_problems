#include <vector>

using namespace std;

int max4(int a, int b, int c, int d){
    return max(max(a, b), max(c, d));
}

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int rows = coins.size();
        int cols = coins[0].size();

        vector<vector<vector<int>>> grid = vector<vector<vector<int>>>(rows, vector<vector<int>>(cols, vector<int>(3, 0)));
        grid[0][0][0] = coins[0][0];
        grid[0][0][1] = coins[0][0] > 0 ? coins[0][0] : 0;
        grid[0][0][2] = coins[0][0] > 0 ? coins[0][0] : 0;

        // First col
        for (int row = 1; row < rows; row++){
            grid[row][0][0] = grid[row-1][0][0] + coins[row][0];
            if (coins[row][0] < 0){
                grid[row][0][1] = max(grid[row-1][0][0], grid[row-1][0][1] + coins[row][0]);
                grid[row][0][2] = max(grid[row-1][0][1], grid[row-1][0][2] + coins[row][0]);

            } else {
                grid[row][0][1] = max(grid[row-1][0][1], grid[row-1][0][0] ) + coins[row][0];
                grid[row][0][2] = max(grid[row-1][0][2], grid[row-1][0][1] ) + coins[row][0];
            }
        }
        // First row
        for (int col = 1; col < cols; col++){
            grid[0][col][0] = grid[0][col-1][0] + coins[0][col];
            if (coins[0][col] < 0){
                grid[0][col][1] = max(grid[0][col-1][1] + coins[0][col], grid[0][col-1][0]);
                grid[0][col][2] = max(grid[0][col-1][2] + coins[0][col], grid[0][col-1][1]);
            }else {
                grid[0][col][1] = max(grid[0][col-1][1], grid[0][col-1][0]) + coins[0][col];
                grid[0][col][2] = max(grid[0][col-1][2], grid[0][col-1][1]) + coins[0][col];
            }
        }

        // Rest
        int c;
        for (int row = 1; row < rows; row++){
            for (int col = 1; col < cols; col++){
                c = coins[row][col];
                if (c < 0){
                    grid[row][col][0] = max(grid[row-1][col][0], grid[row][col-1][0]) + c;
                    grid[row][col][1] = max4(grid[row-1][col][0], grid[row][col-1][0], grid[row-1][col][1] + c, grid[row][col-1][1] + c);
                    grid[row][col][2] = max4(grid[row-1][col][1], grid[row][col-1][1], grid[row-1][col][2] + c, grid[row][col-1][2] + c);
                }
                else {
                    grid[row][col][0] = max(grid[row-1][col][0], grid[row][col-1][0]) + c;
                    grid[row][col][1] = max(grid[row-1][col][1], grid[row][col-1][1]) + c;
                    grid[row][col][2] = max(grid[row-1][col][2], grid[row][col-1][2]) + c;
                }
            }
        }

        return grid[rows-1][cols-1][2];
    }
};