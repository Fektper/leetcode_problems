#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }
        vector<vector<char>> grid;
        int row = 0;
        int col = 0;
        int mode = 1;

        grid.push_back(vector<char>(numRows, '\0'));

        for (char c: s){
            grid[col][row] = c;

            row += mode;
            if (row == -1 || row == numRows){
                mode = -mode;
                row += 2*mode;
            }
            if (mode == -1){
                col -= mode;
                grid.push_back(vector<char>(numRows, '\0'));
            }
        }

        string res;
        for (int row = 0; row < grid[0].size(); row++){
            for (int col = 0; col < grid.size(); col++){
                if (grid[col][row] != '\0'){
                    res.push_back(grid[col][row]);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution solver = Solution();
    solver.convert("AB", 1);
}