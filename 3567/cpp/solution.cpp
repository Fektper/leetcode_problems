#include <vector>
#include <stdio.h>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        int res_rows = rows - k + 1;
        int res_cols = cols - k + 1;
        vector<vector<int>> res = vector<vector<int>>(res_rows, vector<int>(res_cols, 0));
        
        if (k == 1){
            return res;
        }
        
        int prev;
        int minAbsDiff = 0;
        bool diff_found = false;
        for (int i = 0; i < res_rows; i++){
            for (int j = 0; j < res_cols; j++){
                set<int> vals;
                for (int l = 0; l < k; l++){
                    for (int m = 0; m < k; m++){
                        vals.insert(grid[i+l][j+m]);
                    }
                }
                
                prev = *vals.begin();
                minAbsDiff = 0;
                diff_found = false;

                for (int cur: vals){
                    if (cur != prev){
                        if (!diff_found){
                            minAbsDiff = cur-prev;
                            diff_found = true;
                        } else {
                            minAbsDiff = min(minAbsDiff, (cur - prev));
                        }
                        
                    }
                    prev = cur;
                }


                res[i][j] = minAbsDiff;
            }
        }

        return res;
    }
};

int main(){
    Solution solver = Solution();

    vector<vector<int>> test_inp = {{1,-2,3},{2,3,5}};
    int k = 2;
    vector<vector<int>> res = solver.minAbsDiff(test_inp, k);

    for (vector<int> row: res){
        for (int val: row){
            printf("%d, ", val);
        }
        printf("\n");
    }
}