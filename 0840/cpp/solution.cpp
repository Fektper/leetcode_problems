#include <vector>
#include <stdio.h>
using namespace std;

bool isMagic(vector<vector<int>>& grid, int x, int y){
    int numCheck = 0;

    for (int dx= 0; dx <3; dx++){
        for (int dy=0; dy < 3; dy++){
            numCheck += 1<<(grid[y+dy][x+dx]);
        }
    }
    if (numCheck != 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512){
        return false;
    }

    int first_sum = grid[y][x] + grid[y][x+1] + grid[y][x+2];
    int current_sum = 0;

    // Check each column
    for (int dx= 0; dx <3; dx++){
        current_sum = 0;
        for (int dy=0; dy < 3; dy++){
            current_sum += grid[y+dy][x+dx];
        }
        if (current_sum != first_sum){
            return false;
        }
    }

    // Check each row
    for (int dy = 0; dy < 3; dy++){
        current_sum = 0;
        for (int dx = 0; dx < 3; dx++){
            current_sum += grid[y+dy][x+dx];
        }
        if (current_sum != first_sum){
            return false;
        }
    }

    // Diagonals
    if (grid[y][x] + grid[y+1][x+1] + grid[y+2][x+2] != first_sum){
        return false;
    }
    if (grid[y+2][x] + grid[y+1][x+1] + grid[y][x+2] != first_sum){
        return false;
    }

    return true;

}

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        for (int y = 0; y < - 2 + (int)grid.size() ; y++){
            for (int x = 0; x < -2 + (int)grid[0].size(); x++){
                res += isMagic(grid, x, y);
            }
        }

        return res;
    }
};

int main(){
    Solution solver = Solution();
    vector<vector<int>> grid = {{8}};// {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    solver.numMagicSquaresInside(grid);
}