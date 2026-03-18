#include <vector>
#include <numeric>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> running_sums_rows = vector<vector<int>>(rows, vector<int>(cols, 0));

        vector<int> col_count_per_row = vector<int>();
        int running_sum = 0;
        for (int row = 0; row < rows; row++){
            running_sums_rows[row][0] = grid[row][0];
            for (int col = 1; col < cols; col++){
                running_sums_rows[row][col] = running_sums_rows[row][col-1] + grid[row][col];
            }
        }
        
        int count = 0;
        int max_count = cols;
        for (int row = 0; row < rows; row++){
            count = 0;
            while (count < cols && count < max_count && running_sums_rows[row][count] <= k){
                count ++;
            }
            max_count = count;
            if (row != rows-1){
                for (int i = 0; i < count; i++){
                    running_sums_rows[row+1][i] += running_sums_rows[row][i]; 
                }
            }
            
            col_count_per_row.push_back(count);
            if (count == 0){
                break;
            }
        }

        int sol = std::accumulate(col_count_per_row.begin(), col_count_per_row.end(), 0);

        return sol;
        
    }
};

int main(){
    Solution solver = Solution();
    vector<vector<int>> test_input = {{2,9},{3,10},{8,5},{3,8}};
    int test_k = 27;
    int target_output = 6;
    int out = solver.countSubmatrices(test_input, test_k);
    if (out == target_output){
        printf("Test passed\n");
    } else {
        printf("Test failed, expected %d but got %d\n", target_output, out);
    }
}