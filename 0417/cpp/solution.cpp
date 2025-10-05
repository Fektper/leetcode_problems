#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void searchConnections(vector<vector<int>> inits, vector<vector<int>>& heights, vector<vector<bool>>& map, unordered_set<int>* candidates){
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
                    if (candidates != nullptr){
                        candidates->insert(nx + ny*1000);
                    }
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
        unordered_set<int> pacificCandidates;

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
            pacificCandidates.insert(x);
            atlanticStarts[x] = {x, m-1};
        }
        for (int y = 0; y < m; y++){
            pacificStarts[n+y] = {0, y};
            pacificCandidates.insert(y*1000);
            atlanticStarts[n+y] = {n-1, y};;
        }

        searchConnections(pacificStarts, heights, toPacific, &pacificCandidates);
        searchConnections(atlanticStarts, heights, toAtlantic, nullptr);

        vector<vector<int>> result;
        int x; int y;
        for (int d: pacificCandidates){
            x = d % 1000;
            y = d / 1000;
            if (toAtlantic[y][x]){
                result.push_back({y, x});
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