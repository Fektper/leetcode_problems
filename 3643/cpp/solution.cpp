#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        int top = k/2;
        int a;
        for (int i = 0; i < top; i++){
            int r1 = x + i;
            int r2 = x+k-i-1;

            for (int j = 0; j < k; j++){
                a = grid[r1][y+j];
                grid[r1][y+j] = grid[r2][y+j];
                grid[r2][y+j] = a;
            }
        }
        return grid;
    }
};

int main(){
    vector<vector<int>> test_input = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> target_output = {{1,2,3,4},{13,14,15,8},{9,10,11,12},{5,6,7,16}};

    Solution solver = Solution();
    vector<vector<int>> res = solver.reverseSubmatrix(test_input, 1, 0, 3);

    int total_abs_diff = 0;
    for (int i = 0; i < test_input.size(); i++){
        for (int j = 0; j < test_input[i].size(); j++){
            total_abs_diff += max(res[i][j], target_output[i][j]) - min(res[i][j], target_output[i][j]);
        }
    }

    if (total_abs_diff == 0){
        printf("Test passed!\n");
    }
    else{
        printf("Test failed!\n");
    }
}