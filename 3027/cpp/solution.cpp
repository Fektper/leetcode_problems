#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
        // Points are sorted in a way that if they have same x position, higher one comes first -> optimal
        int count = 0;
        int running_max_height_below_a;
        int min_height = -1000000001; // all points are in [-10^9, 10^9]
        int n = points.size();
        for (int i = 0; i < n - 1; i++){
            running_max_height_below_a = min_height;
            for (int j = i+1; j < points.size(); j++){
                if (points[j][1] == points[i][1]){
                    count++;
                    break;
                }
                if (points[j][1] > points[i][1]){
                    continue;
                }
                if (running_max_height_below_a >= points[j][1]){
                    continue;
                }
                else{
                    running_max_height_below_a = points[j][1];
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    vector<vector<vector<int>>> test_inputs = {
        {{1,1},{2,2},{3,3}}, // 0
        {{6,2},{4,4},{2,6}}, // 2
        {{3,1},{1,3},{1,1}}, // 2
    };
    vector<int> target_results = {0, 2, 2};
    
    bool passed = true;
    Solution solver = Solution();

    for (int i = 0;i < test_inputs.size(); i++){
        int res = solver.numberOfPairs(test_inputs[i]);
        if (res != target_results[i]){
            printf("Test %d failed! Expected %d but got %d!\n", i, target_results[i], res);
            passed = false;
        }
    }
    if (!passed){
        printf("Not all tests ran successfully!\n");
    }
    else{
        printf("All tests passed!\n");
    }
}