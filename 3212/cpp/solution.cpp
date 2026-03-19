#include <vector>
#include <stdio.h>

using namespace std;


struct XYCounter{
    int xs;
    int ys;
};

bool isValid(XYCounter cell){
    return cell.xs > 0 && cell.xs == cell.ys;
}

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        vector<vector<XYCounter>> per_row_xys = vector<vector<XYCounter>>(rows, vector<XYCounter>(cols, {0, 0}));
        for (int row = 0; row < rows; row++){
            // Init first element
            per_row_xys[row][0] = {grid[row][0] == 'X', grid[row][0] == 'Y'};
            
            // Iteratively calculate next elements
            for (int col = 1; col < cols; col++){
                per_row_xys[row][col] = {per_row_xys[row][col-1].xs + (grid[row][col] == 'X'), per_row_xys[row][col-1].ys + (grid[row][col] == 'Y')};
            }

            for (int col = 0; col < cols; col++){
                if (row >= 1){
                    per_row_xys[row][col].xs += per_row_xys[row-1][col].xs;
                    per_row_xys[row][col].ys += per_row_xys[row-1][col].ys;
                }
                

                if (isValid(per_row_xys[row][col])){
                    res++;
                }
            }
        }


        return res;
    }
};

int main(){
    Solution solver = Solution();
    vector<vector<char>> test_input = {{'X','Y','.'},{'Y','.','.'}};
    int target_res = 3;
    int res = solver.numberOfSubmatrices(test_input);

    if (target_res == res){
        printf("Test passed!\n");
    }
    else {
        printf("Test failed! Expected %d but got %d\n", target_res, res);
    }
}