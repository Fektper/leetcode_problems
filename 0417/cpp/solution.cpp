#include <vector>
#include <queue>

using namespace std;

void searchConnections(vector<vector<int>> inits, vector<vector<int>>& heights, vector<vector<bool>>& map){
    int n = map[0].size();
    int m = map.size();

    queue<vector<int>, deque<vector<int>>> points(std::deque<vector<int>>(inits.begin(), inits.end()));

    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int nx; int ny;
    vector<int> current;
    while (points.size() > 0){
        current = points.front();
        points.pop();

        for (vector<int> dir: dirs){
            nx = current[0] + dir[0];
            ny = current[1] + dir[1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (heights[ny][nx] >= heights[current[1]][current[0]] && !map[ny][nx]){
                    map[ny][nx] = true;
                    points.push({nx, ny});
                }
            }
        }
    }
}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights[0].size();
        int m = heights.size();

        vector<vector<bool>> toAtlantic(m, vector<bool>(n, false));
        vector<vector<bool>> toPacific(m, vector<bool>(n, false));

        // Init
        for (int x = 0; x < n; x++){
            toPacific[0][x] = true;
            toAtlantic[m-1][x] = true;
        }
        for (int y = 0; y < m; y++){
            toPacific[y][0] = true;
            toAtlantic[y][n-1] = true;
        }

        vector<vector<int>> pacificStarts(n+m); // 1 too much
        vector<vector<int>> atlanticStarts(n+m);

        for (int x = 0; x < n; x++){
            pacificStarts[x] = {x, 0};
            atlanticStarts[x] = {x, m-1};
        }
        for (int y = 0; y < m; y++){
            pacificStarts[n+y] = {0, y};
            atlanticStarts[n+y] = {n-1, y};;
        }

        searchConnections(pacificStarts, heights, toPacific);
        searchConnections(atlanticStarts, heights, toAtlantic);


        vector<vector<int>> result;
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                if (toAtlantic[y][x] && toPacific[y][x]){
                    result.push_back({y, x});
                }
            }
        }
        return result;
    }
};

int main(){
    vector<vector<int>> test_input = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution solver = Solution();
    solver.pacificAtlantic(test_input);
}