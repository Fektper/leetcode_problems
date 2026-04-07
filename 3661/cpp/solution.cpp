#include <vector>
#include <algorithm>


using namespace std;

struct Robot{
    int pos;
    int left_dist;
    int right_dist;
};

class RobotPositionCompareSmaller{
    public:
    bool operator() (Robot& a, Robot& b){
        return a.pos < b.pos;
    }
};

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<Robot> robs = vector<Robot>(n);
        for (int i = 0; i < n; i++){
            robs[i] = {robots[i], distance[i], distance[i]};
        }

        sort(walls.begin(), walls.end());
        sort(robs.begin(), robs.end(), RobotPositionCompareSmaller());

        if (n != 1){


            robs[0].right_dist = min(robs[0].right_dist, robs[1].pos - robs[0].pos - 1);
            robs[n-1].left_dist = min(robs[n-1].left_dist, robs[n-1].pos - robs[n-2].pos - 1);
            
            for (int i = 1; i < n - 1; i++){
                robs[i].left_dist = min(robs[i].left_dist, robs[i].pos - robs[i-1].pos - 1);
                robs[i].right_dist = min(robs[i].right_dist, robs[i+1].pos - robs[i].pos - 1) ;
            }
        }

        int last_left = 0;
        int last_right = 0;
        int this_left;
        int this_right;
        int prev_right_reach = -1;

        for (Robot rob: robs){
            this_left = max(last_left + (upper_bound(walls.begin(), walls.end(), rob.pos) - lower_bound(walls.begin(), walls.end(), rob.pos - rob.left_dist)), last_right + (upper_bound(walls.begin(), walls.end(), rob.pos) - lower_bound(walls.begin(), walls.end(), max(prev_right_reach + 1, rob.pos - rob.left_dist))));

            this_right = max(last_left, last_right) + upper_bound(walls.begin(), walls.end(), rob.pos + rob.right_dist) - lower_bound(walls.begin(), walls.end(), rob.pos);

            last_left = this_left;
            last_right = this_right;
            prev_right_reach = rob.pos + rob.right_dist;
        }

        return max(last_left, last_right);

    }
};

int main(){
    vector<int> robots = {14,59,57,85,58,5,55,28,19,56,33,11,40,51,71,78,70,1,87,92,39,72,83,53,65,62,94,75,10,3,8,31,22,18,7,50,68,25,44,76,60,88,41,90,42,95,36,69,24,20,89,67,29,21,45,13,16,4,47,2,66};
    vector<int> distance = {10,2,9,3,3,3,6,1,8,6,6,7,7,10,5,3,4,4,3,1,9,6,5,9,8,3,1,1,7,6,2,7,4,3,7,1,8,1,2,2,4,6,3,7,4,4,5,7,2,7,1,3,9,1,2,8,9,2,10,9,5};
    vector<int> walls = {21,20,74,19,13,45,70,38,56,4,81,75,62,57,33,63,30,44,65,85,73,53,47,14,36,29,67,40,77,69,84,89,55,5,35,24,83,8,79,88,48,2,58,6,26,43,7,42,87,34,1,61,32,68,18,82};

    Solution solver = Solution();
    solver.maxWalls(robots, distance, walls);
}