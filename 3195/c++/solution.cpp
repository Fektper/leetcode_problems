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

        for (int row = 0; row < row_count; row++){
            for (int col = 0; col < col_count; col++){
                if (!grid.at(row).at(col)){
                    continue;
                }

                if (col < min_left){
                    min_left = col;
                }
                if (col > max_right){
                    max_right = col;
                }

                if (row < min_top){
                    min_top  = row;
                }
                max_bot = row;
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