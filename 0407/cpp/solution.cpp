#include <vector>
#include <queue>

#include <iostream>

using namespace std;

struct GridPoint{
    int x;
    int y;
    int height;
};

class GridPointCompare{
public:
    bool operator() (GridPoint& a, GridPoint& b) const{
        return a.height > b.height;
    }
};



class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        
        priority_queue<GridPoint, vector<GridPoint>, GridPointCompare> borders;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int x = 0; x < m; x++){
            borders.push({x, 0, heightMap[0][x]});
            borders.push({x, n-1, heightMap[n-1][x]});
            visited[0][x] = true;
            visited[n-1][x] = true;

        }

        for (int y = 0; y < n; y++){
            borders.push({0, y, heightMap[y][0]});
            borders.push({m-1, y, heightMap[y][m-1]});
            visited[y][0] = true;
            visited[y][m-1] = true;
        }

        
        int totalSum = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        GridPoint current;
        int nx; int ny;

        while (borders.size() > 0){
            current = borders.top();
            borders.pop();

            for (int* dir: dirs){
                nx = current.x + dir[0];
                ny = current.y + dir[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                    if (!visited[ny][nx]){
                        visited[ny][nx] = true;
                        if (heightMap[ny][nx] < current.height){
                            totalSum += current.height - heightMap[ny][nx];
                            borders.push({nx, ny, current.height});
                        }
                        else {
                            borders.push({nx, ny, heightMap[ny][nx]});
                        }
                    }
                }
            }
        }

        

        return totalSum;
    }
};

int main(){
    Solution solver = Solution();
    // vector<vector<int>> test_input = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    // std::cout << solver.trapRainWater(test_input) << std::endl;

    vector<vector<int>> test_input = {{78,16,94,36},{87,93,50,22},{63,28,91,60},{64,27,41,27},{73,37,12,69},{68,30,83,31},{63,24,68,36}};
    std::cout << solver.trapRainWater(test_input) << std::endl;
}