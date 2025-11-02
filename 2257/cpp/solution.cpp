#include <vector>
#include <unordered_set>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        int x; int y;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


        for (vector<int> w: walls){
            x = w[1]; y = w[0];
            grid[y][x] = 2;
        }
        
        int px; int py; int dx; int dy;
        for (vector<int> g: guards){
            x = g[1]; y = g[0];
            grid[y][x] = 1;
        }

        for (vector<int> g: guards){
            x = g[1]; y = g[0];
            for (vector<int> dir: dirs){
                dy = dir[0]; dx = dir[1];
                px = x + dx; py = y + dy;
                while (px >= 0 && px < n && py >= 0 && py < m && grid[py][px] != 1 && grid[py][px] != 2){
                    grid[py][px] = 3;
                    px += dx;
                    py += dy;
                }
            }
        }

        int res = 0;
        for (int y = 0; y < m; y++){
            for (int x = 0; x < n; x++){
                if (grid[y][x] == 0){
                    res++;
                }
            }
        }
        return res;

    }
};

int main(){
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};

    Solution solver = Solution();
    solver.countUnguarded(4, 6, guards, walls);
}