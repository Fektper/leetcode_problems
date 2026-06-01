#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int total_cost = 0;
        int step = 0;
        for (int i = cost.size() - 1; i >= 0; i--){
            step++;
            if (step == 3){
                step = 0;
                continue;
            }
            total_cost += cost[i];
        }
        return total_cost;
    }
};