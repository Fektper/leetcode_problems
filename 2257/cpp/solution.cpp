#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int res = 0;

        for (vector<int> g: guards){
            grid[g[0]][g[1]] = 1;
        }
        for (vector<int> w: walls){
            grid[w[0]][w[1]] = 2;
        }

        bool vis = false;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int dx; int dy; int px; int py;
        for (int y = 0; y < m; y++){
            for (int x = 0; x < n; x++){
                vis = false;
                if (grid[y][x] == 1 || grid[y][x] == 2){
                    continue;
                }
                for (vector<int> dir: dirs){
                    if (vis){
                        break;
                    }
                    dx = dir[0]; dy = dir[1];
                    px = x; py = y;

                    while (px >= 0 && px < n && py >= 0 && py < m && grid[py][px] != 2){
                        if (grid[py][px] == 1){
                            vis = true;
                            break;
                        }
                        px += dx;
                        py += dy;
                    }
                }

                if (!vis){
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