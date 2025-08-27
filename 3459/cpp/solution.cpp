#include <vector>
#include <stdio.h>
#include <tuple>

using namespace std;

int getNextNum(int current_num){
    return current_num == 2 ? 0 : 2;
}

bool isInGrid(vector<vector<int>>& grid, int x, int y){
    return x >= 0 && y >= 0 && x < grid.at(0).size() && y < grid.size();
}

int findVSet0Turn(vector<vector<int>>& grid, int px, int py, int dx, int dy, int current_num, int current_area){
    // this area has already been added, only check next
    int next_num = current_num == 2 ? 0 : 2;
    int next_px = px + dx;
    int next_py = py + dy;

    while(isInGrid(grid, next_px, next_py) && grid.at(next_py).at(next_px) == next_num){
        current_area += 1;
        next_num = next_num == 2 ? 0 : 2;
        next_px += dx;
        next_py += dy;
    }
    return current_area;
}

int findVSet1Turn(vector<vector<int>>& grid, int px, int py, int dx, int dy, int current_num, int current_area){
    // this area has already been added, only check next
    int next_num = current_num == 2 ? 0 : 2;
    // First calculate if we can go further straight
    int straight_area = current_area;
    int next_px = px + dx;
    int next_py = py + dy;

    if (isInGrid(grid, next_px, next_py)){
        if (grid.at(next_py).at(next_px) == next_num){
            straight_area = findVSet1Turn(grid, next_px, next_py, dx, dy, next_num, current_area + 1);
        }
    }

    // Calcuclate area if we make right turn
    int turn_area = 0;
    int turn_dx = dx*dy == 1 ? -dx : dx;
    int turn_dy = dx*dy == 1 ? dy : -dy;

    next_px = px + turn_dx;
    next_py = py + turn_dy;
    if (isInGrid(grid, next_px, next_py)){
        if (grid.at(next_py).at(next_px) == next_num){
            turn_area = findVSet0Turn(grid, next_px, next_py, turn_dx, turn_dy, next_num, current_area + 1);
        }
    }

    return std::max(turn_area, straight_area);
}

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int max_area = 0;
        vector<tuple<int, int>> start_positions(0);

        for (int y = 0; y < grid.size(); y++){
            for (int x = 0; x < grid.at(0).size(); x++){
                if (grid[y][x] == 1){
                    start_positions.push_back({x, y});
                }
            }
        }

        for (tuple<int, int> start_pos: start_positions){
            for (int dx: {-1, 1}){
                for (int dy: {-1, 1}){
                    max_area = std::max(max_area, findVSet1Turn(grid, get<0>(start_pos), get<1>(start_pos), dx, dy, 1, 1));
                }
            }
        }
        return max_area;
    }
};


int main(){
    vector<vector<int>> test_input = {{2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    int target_solution = 5;

    Solution solver = Solution();
    int res = solver.lenOfVDiagonal(test_input);
    if (res == target_solution){
        printf("Test passed!\n");
    }
    else{
        printf("Test failed! Expected %d but got %d\n", target_solution, res);
    }
}