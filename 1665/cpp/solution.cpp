#include <vector>
#include <algorithm>

using namespace std;

class TaskCompare{
    public:
    bool operator() (const vector<int>& a, const vector<int>& b) const{
        return a[1] - a[0] < b[1] - b[0];
    }
};

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        std::sort(tasks.begin(), tasks.end(), TaskCompare());
        int current_energy = 0;
        int diff_min;
        int diff_req;
        for (vector<int> task: tasks){
            current_energy += task[0];
            if (current_energy >= task[1]){
                continue;
            }
            else {
                current_energy = task[1];
            }
        }
        return current_energy;
    }
};

int main(){
    vector<vector<int>> test = {{1, 2}, {2, 4}, {4, 8}};
    Solution solver = Solution();
    solver.minimumEffort(test);
    // [[1,3],[2,4],[8,9][10,11],[10,12],]
}