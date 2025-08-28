#include <vector>
#include <stdio.h>

using namespace std;

void inlineBubbleSort(vector<vector<int>>& grid, int start_row, int start_col, int n, bool asc){
    int pre_stop = 0;
    int changed = true;
    int row = start_row;
    int col = start_col;
    int swapper;
    for(int _ = 0; _ < std::min(n-start_row, n-start_col); _++){
        row = start_row;
        col = start_col;
        changed = false;
        while (row < n-pre_stop-1 && col < n-pre_stop-1){
            

            if (asc){
                if (grid[col][row] > grid[col+1][row+1]){
                    changed = true;
                    swapper = grid[col+1][row+1];
                    grid[col+1][row+1] = grid[col][row];
                    grid[col][row] = swapper;
                }
            }
            else{
                if (grid[col][row] < grid[col+1][row+1]){
                    changed = true;
                    swapper = grid[col+1][row+1];
                    grid[col+1][row+1] = grid[col][row];
                    grid[col][row] = swapper;
                }
            }

            row++;
            col++;
        }
        pre_stop++;
        if(!changed){
            break;
        }
    }
}

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Sort descending lower half
        for (int i = 0; i < n; i++){
            inlineBubbleSort(grid, 0, i, n, false);
        }
        // Sort ascending upper half
        for (int i = 1; i < n; i++){
            inlineBubbleSort(grid, i, 0, n, true);
        }

        return grid;
    }
};


bool matrixEquals(vector<vector<int>>& mat1, vector<vector<int>>& mat2){
    int n = mat1.size();
    int m = mat1.at(0).size();

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (mat1[i][j] != mat2[i][j]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    vector<vector<int>> test_input = {{-1,-2,-3},{-3,-3,-2},{-4,-4,0}};
    vector<vector<int>> target_result = {{0,-2,-3},{-3,-1,-2},{-4,-4,-3}};

    Solution solver = Solution();
    vector<vector<int>> res = solver.sortMatrix(test_input);
    if (matrixEquals(res, target_result)){
        printf("Test passed!\n");
    }
    else{
        printf("Test failed\n");
    }
}