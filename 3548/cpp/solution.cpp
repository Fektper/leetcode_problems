#include <vector>
#include <unordered_set>
#include <stdio.h>

using namespace std;


bool isSolvable(unordered_set<long long int>& removals, long long int cum_sum, long long int grid_sum){
    // grid_sum - x - 2*(cum_sum - x) == 0
    // -> x = 2*cum_sum - grid_sum
    long long int target = 2*cum_sum - grid_sum;
    if (target == 0){
        return true;
    }

    if (target < 0){
        return false;
    }

    return removals.find(target) != removals.end();
}

bool rowCheck(vector<vector<int>>& grid, long long int grid_sum, int start, int dir){
    int rows = grid.size();
    int cols = grid[0].size();

    unordered_set<long long int> removals = unordered_set<long long int>();
    long long int cum_sum = 0;

    for (int j = 0; j < cols; j++){
        cum_sum += grid[start][j];
    }
    removals.insert(grid[start][0]);
    removals.insert(grid[start][cols-1]);

    if (isSolvable(removals, cum_sum, grid_sum)){
        return true;
    }
    for (int j = 1; j < cols-1; j++){
        removals.insert(grid[start][j]);
    }

    for (int row = start + dir; row < rows && row >= 0; row += dir){
        for (int j = 0; j < cols; j++){
            cum_sum += grid[row][j];
            if (cols > 1){
                removals.insert(grid[row][j]);
            } else {
                removals = {grid[row][0], grid[start][0]};
            }
            
        }
        if (isSolvable(removals, cum_sum, grid_sum)){
            return true;
        }
    }
    return false;
}

bool colCheck(vector<vector<int>>& grid, long long int grid_sum, int start, int dir){
    int rows = grid.size();
    int cols = grid[0].size();

    unordered_set<long long int> removals = unordered_set<long long int>();
    long long int cum_sum = 0;

    for (int i = 0; i < rows; i++){
        cum_sum += grid[i][start];
    }
    removals.insert(grid[0][start]);
    removals.insert(grid[rows-1][start]);
    if (isSolvable(removals, cum_sum, grid_sum)){
        return true;
    }
    for (int i = 1; i < rows-1; i++){
        removals.insert(grid[i][start]);
    }

    for (int col = start + dir; col < cols && col >= 0; col += dir){
        for (int i = 0; i < rows; i++){
            cum_sum += grid[i][col];
            if (rows > 1){
                removals.insert(grid[i][col]);
            } else{
                removals = {grid[0][col], grid[0][start]};
            }
        }
        if (isSolvable(removals, cum_sum, grid_sum)){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        long long int grid_sum = 0;

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                grid_sum += grid[i][j];
            }
        }

        if (rowCheck(grid, grid_sum, 0, 1) || rowCheck(grid, grid_sum, rows-1, -1)){
            return true;
        }

        if (colCheck(grid, grid_sum, 0, 1) || colCheck(grid, grid_sum, cols-1, -1)){
            return true;
        }
        return false;
        
    }
};

int main(){
    vector<vector<int>> test_inpt = {{10,5,4,5}};
    bool target_res = false;
    Solution solver = Solution();
    bool res = solver.canPartitionGrid(test_inpt);

    if (res == target_res){
        printf("Test passed\n");
    }
    else {
        printf("Test failed! Expected %d, but got %d", target_res, res);
    }
}