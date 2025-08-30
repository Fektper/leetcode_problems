#include <vector>

using namespace std;

bool checkRow(vector<vector<char>>& board, int row){
    bool occured[] = {false, false, false, false, false, false, false, false, false, false};

    char current_char;
    int current_int;
    for (int i = 0; i < 9; i++){
        current_char = board[row][i];
        if (current_char == '.'){
            continue;
        }
        current_int = current_char - '0';
        if (occured[current_int]){
            return false;
        }
        occured[current_int] = true;
    }
    return true;
}

bool checkCol(vector<vector<char>>& board, int col){
    bool occured[] = {false, false, false, false, false, false, false, false, false, false};

    char current_char;
    int current_int;
    for (int i = 0; i < 9; i++){
        current_char = board[i][col];
        if (current_char == '.'){
            continue;
        }
        current_int = current_char - '0';
        if (occured[current_int]){
            return false;
        }
        occured[current_int] = true;
    }
    return true;
}

bool checkSquare(vector<vector<char>>& board, int col, int row){
    bool occured[] = {false, false, false, false, false, false, false, false, false, false};
    row = row*3;
    col = col*3;

    char current_char;
    int current_int;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            current_char = board[row + i][col + j];
            if (current_char == '.'){
                continue;
            }
            current_int = current_char - '0';
            if (occured[current_int]){
                return false;
            }
            occured[current_int] = true;
        }
    }
    return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            if (!checkRow(board, i) || !checkCol(board, i)){
                return false;
            }
        }

        for (int row = 0; row < 3; row++){
            for (int col = 0; col < 3; col++){
                if(!checkSquare(board, col, row)){
                    return false;
                }
            }
        }
        return true;
    }
};