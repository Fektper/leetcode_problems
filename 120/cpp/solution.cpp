#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev = triangle[0];
        int total_min = prev[0];
        int current_min;
        for (int row = 1; row < triangle.size(); row++){
            total_min = prev[0] + triangle[row][0];

            vector<int> newPrev;
            for (int col = 0; col < triangle[row].size(); col++){
                current_min = triangle[row][col] + min(prev[min(col, (int) prev.size()-1)], prev[max(0, col-1)]);
                newPrev.push_back(current_min);
                if (current_min < total_min){
                    total_min = current_min;
                }
            }
            prev = newPrev;

        }
        return total_min;
    }
};

int main(){
    vector<vector<int>> test = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution solver = Solution();

    solver.minimumTotal(test);
}