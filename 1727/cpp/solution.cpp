#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> consecutive_ones = vector<vector<int>>(rows, vector<int>(cols, 0));
        for (int x = 0; x < cols; x++){
            int running_sum = 0;
            for (int y = 0; y < rows; y++){
                if (matrix[y][x] == 1){
                    running_sum += 1;
                }
                else {
                    running_sum = 0;
                }
                consecutive_ones[y][x] = running_sum;
            }
        }
        int max = 0;
        for (int row = 0; row < rows; row++){
            sort(consecutive_ones[row].begin(), consecutive_ones[row].end(), std::greater<int>());
            for (int i = 1; i <= cols; i++){
                consecutive_ones[row][i-1] *= i;
            }
            int cand = *std::max_element(consecutive_ones[row].begin(), consecutive_ones[row].end());
            max = max > cand ? max : cand;
        }
        return max;
    }
};