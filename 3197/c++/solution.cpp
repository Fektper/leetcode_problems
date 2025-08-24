#include <stdio.h>
#include <vector>

using namespace std;

struct Rect { // Left/top incluseive, right/bot exclusive
    int top;
    int left;
    int right;
    int bot;
};

int minimumSingleCell(vector<vector<int>>& grid, Rect area){

}

int minimumTwoSplit(vector<vector<int>>& grid, Rect area){

}

int optimalTwoOneSplit(vector<vector<int>>& grid, Rect excluded_area){

}

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        // Idea: Create 3 rectangles that span entire grid, then calculate minimum necessary rect inside each.
        // Iterate all possibilitys and take best
        int row_count = grid.size();
        int col_count = grid.at(0).size();

        // Iterate first rectangle, from this calculate other two to span entire area
        int best_solution = row_count * col_count;

        for (int row_end = 1; row_end <= row_count; row_end++){
            for (int col_end = 1; col_end <= col_count; col_end++){
                if (row_end == row_count && col_end == col_count){
                    continue;
                }

                int test_solution = 0;
                Rect rect1;
                rect1.top = 0; rect1.left = 0; rect1.right = col_end; rect1.bot = row_end;

                if (row_end == row_count || col_end == col_count){
                    // Full row/col taken by first rect
                    test_solution = minimumSingleCell(grid, rect1) + minimumTwoSplit(grid, rect1);
                    best_solution = std::min(test_solution, best_solution);
                    continue;
                }

                // Default behavior, other two rects are predefined, but can be split in two ways
                // 2 + 1 or 1 + 2 split
                test_solution = minimumSingleCell(grid, rect1) + optimalTwoOneSplit(grid, rect1);
                best_solution = std::min(best_solution, test_solution);
                
            }
        }
        return 3;
    }
};



int main(){
    int target_sol = 5;
    vector<int> row1 = {1,0,1,0};
    vector<int> row2 =  {0,1,0,1};
    vector<vector<int>> test_input = {row1, row2};

    Solution* solver = new Solution();
    int res = solver->minimumSum(test_input);

    if (res == target_sol){
        printf("Test passed!\n");
    }
    else{
        printf("Test failed! Expected %d but got %d\n", target_sol, res);
    }
}