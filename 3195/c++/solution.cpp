#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row_count = grid.size();
        int col_count = grid.at(0).size();

        int min_left, min_top, max_right, max_bot;
        min_left = min_top = std::max(row_count, col_count);
        max_right = max_bot = 0;

        // Find first row with 1s and last row with 1s
        bool row_has_one = false;
        for (int row = 0; row < row_count; row++){
            for (int col = 0; col < col_count; col++){
                if (grid.at(row).at(col)){
                    row_has_one = true;
                    min_top = row; // This is final
                    min_left = col;
                    max_right = col;
                    break;
                }
            }
            if (row_has_one){
                break;
            }
        }

        row_has_one = false;
        for (int row = row_count - 1; row >= 0; row--){
            for (int col = 0; col < col_count; col++){
                if (grid.at(row).at(col)){
                    row_has_one = true;
                    max_bot = row; // This is final
                    min_left = std::min(col, min_left);
                    max_right = std::max(col, max_right);
                    break;
                }
            }
            if (row_has_one){
                break;
            }
        }
        
        // min_top and max_bot set, left/right need to be optimised

        for (int row = min_top; row <= max_bot; row ++){
            for (int col = 0; col < min_left; col ++){
                if (grid.at(row).at(col)){
                    min_left = col;
                    break;
                }
            }
            for (int col = col_count - 1; col > max_right; col--){
                if (grid.at(row).at(col)){
                    max_right = col;
                    break;
                }
            }
        }
        return (max_right - min_left + 1) * (max_bot - min_top + 1);
    }
};

int main(int argc, char* argv[]){
    vector<int> row1 = {0, 1, 0};
    vector<int> row2 = {1, 0, 1};

    vector<vector<int>> test_input = {row1, row2};

    Solution *sol = new Solution();
    int area = sol->minimumArea(test_input);
    if (area == 6){
        printf("Test passed\n");
    }
    else{
        printf("Test failed, expected 6 but got %d\n", area);
    }
}