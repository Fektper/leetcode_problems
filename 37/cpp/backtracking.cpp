#include <vector>
#include <stdio.h>

using namespace std;


bool sudokuCompare(vector<vector<char>> a, vector<vector<char>> b){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (a[i][j] != b[i][j]){
                return false;
            }
        }
    }
    return true;
}


bool backTrackSolve(vector<vector<char>>& board, int row, int col){
    if (col == 0 && row == 9){
        return true;
    }
    int next_col = (col + 1) % 9;
    int next_row = next_col == 0 ? row + 1 : row;

    // If value already set, continue
    if (board[row][col] != '.'){
        return backTrackSolve(board, next_row, next_col);
    }

    int cube_row = row / 3;
    int cube_col = col / 3;
    vector<bool> occured = {false, false, false, false, false, false, false, false, false};
    char current_val;

    // Get values in rows
    for (int i = 0; i < 9; i++){
        current_val = board[row][i];
        if (current_val != '.'){
            occured[current_val - '1'] = true;
        }
    }
    // Get values in cols
    for (int i = 0; i < 9; i++){
        current_val = board[i][col];
        if (current_val != '.'){
            occured[current_val - '1'] = true;
        }
    }
    // Get values in cube
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            current_val = board[cube_row * 3 + i][cube_col * 3 + j];
            if (current_val != '.'){
                occured[current_val - '1'] = true;
            }
        }
    }

    // Try all possible values!
    for (int i = 0; i < occured.size(); i++){
        if (!occured[i]){
            board[row][col] = '1' + i;
            if (backTrackSolve(board, next_row, next_col)){
                return true;
            }
        }
    }
    board[row][col] = '.';
    return false; // One Solution must be right!

}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backTrackSolve(board, 0, 0);
    }
};


int main(){
    
    vector<vector<char>> test_input = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    
    vector<vector<char>> target_output = {{'5','3','4','6','7','8','9','1','2'},{'6','7','2','1','9','5','3','4','8'},{'1','9','8','3','4','2','5','6','7'},{'8','5','9','7','6','1','4','2','3'},{'4','2','6','8','5','3','7','9','1'},{'7','1','3','9','2','4','8','5','6'},{'9','6','1','5','3','7','2','8','4'},{'2','8','7','4','1','9','6','3','5'},{'3','4','5','2','8','6','1','7','9'}};

    Solution solver = Solution();

    solver.solveSudoku(test_input);
    if (sudokuCompare(test_input, target_output)){
        printf("Test passed!");
    }
    else {
        printf("Test failed!\n");
    }
}