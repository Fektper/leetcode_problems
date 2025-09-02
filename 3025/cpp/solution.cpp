#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        std::stable_sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){return a[1] > b[1];}); // Sort by decreasing height
        int min_height = points[points.size()-1][1];
        std::stable_sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];}); // Then sort by increasing x. 
        // Points are sorted in a way that if they have same x position, higher one comes first -> optimal
        int count = 0;
        int running_max_height_below_a;
        int a_y;
        int b_y;
        for (int i = 0; i < points.size() - 1; i++){
            a_y = points[i][1];
            running_max_height_below_a = min_height - 1;
            for (int j = i+1; j < points.size(); j++){
                b_y = points[j][1];
                if (b_y > a_y){
                    continue;
                }
                if (running_max_height_below_a >= b_y){
                    continue;
                }
                running_max_height_below_a = b_y;
                count++;
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