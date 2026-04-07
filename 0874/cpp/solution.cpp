#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> turn(int dx, int dy, int t){
    int h;
    if (t == -1){
        // Right turn x = y
        // y = x
        h = dx;
        dx = dy;
        dy = -h;
    } else {
        h = dx;
        dx = -dy;
        dy = h;
    }
    return {dx, dy};
}

bool is_obstacle(unordered_map<int, unordered_set<int>>& obs, int x, int y){
    if (obs.find(y) == obs.end()){
        return false;
    }
    else if (obs[y].find(x) == obs[y].end()){
        return false;
    }
    return true;
}

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        // Handle obstacles as map
        unordered_map<int, unordered_set<int>> obs = unordered_map<int, unordered_set<int>>();
        int x;
        int y;
        for (vector<int> obstacle: obstacles){
            x = obstacle[0];
            y = obstacle[1];
            if (obs.find(y) == obs.end()){
                obs[y] = {x};
            }
            else {
                obs[y].insert(x);
            }
        }
        int dx = 0;
        int dy = 1;
        x = 0;
        y = 0;
        int d = 0;
        int nx;
        int ny;
        vector<int> new_dir;
        for (int cmd: commands){
            if (cmd  < 0){
                new_dir = turn(dx, dy, cmd);
                dx = new_dir[0];
                dy = new_dir[1];
            }
            else {
                for (int i = 0; i < cmd; i++){
                    nx = x + dx;
                    ny = y + dy;
                    if (is_obstacle(obs, nx, ny)){
                        break;
                    }
                    else {
                        x = nx;
                        y = ny;
                        d = max(d, x*x + y*y);
                    }
                }
            }
        }

        return d;

    }
};

int main(){
    vector<int> moves = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2, 4}};

    Solution solver = Solution();
    solver.robotSim(moves, obstacles);
}