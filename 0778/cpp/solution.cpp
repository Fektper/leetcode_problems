#include <vector>
#include <queue>

using namespace std;

struct GridPos{
    int x;
    int y;
    int height;
};

class GridGreater{
    public:
    bool operator()(const GridPos& a, const GridPos& b) const {
        return a.height > b.height;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<GridPos, vector<GridPos>, GridGreater> gridQueue;

        visited[0][0] = true;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        gridQueue.push({0, 0, grid[0][0]});
        GridPos current;
        int nx; int ny;
        int current_height = grid[0][0];
        while(!visited[m-1][n-1]){
            current = gridQueue.top();
            gridQueue.pop();
            current_height = max(current_height, current.height);
            

            for (vector<int> dir: dirs){
                nx = current.x + dir[0];
                ny = current.y + dir[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[ny][nx]){
                    gridQueue.push({nx, ny, grid[ny][nx]});
                    visited[ny][nx] = true;
                }
            }
        }
        return max(current_height, grid[m-1][n-1]);
    }
};