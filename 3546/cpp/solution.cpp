#include <vector>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        long long int grid_sum = 0;

        vector<long long int> row_sums = vector<long long int>(rows, 0);
        vector<long long int> col_sums = vector<long long int>(cols, 0);

        long long int current_sum = 0;
        for (int i = 0; i < rows; i++){
            current_sum = 0;
            for (int j = 0; j < cols; j++){
                current_sum += grid[i][j];
            }
            row_sums[i] = current_sum + (i > 0 ? row_sums[i-1] : 0);
            grid_sum += current_sum;
        }

        if (grid_sum % 2 == 1){
            return false;
        }

        bool row_res = binary_search(row_sums.begin(), row_sums.end(), grid_sum/2);
        if (row_res){
            return true;
        }


        for (int j = 0; j < cols; j++){
            current_sum = 0;
            for (int i = 0; i < rows; i++){
                current_sum += grid[i][j];
            }
            col_sums[j] = current_sum + (j > 0 ? col_sums[j-1] : 0);
        }
        bool col_res = binary_search(col_sums.begin(), col_sums.end(), grid_sum/2);

        return col_res;
    }
};

int main(){
    vector<vector<int>> inpt = {{54756,54756}};
    Solution solver = Solution();
    solver.canPartitionGrid(inpt);
}