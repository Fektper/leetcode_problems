#include <vector>
#include <stdio.h>

using namespace std;

bool rowShiftable(vector<int>& row, int k, int dir){
    int n = row.size();
    int new_start = dir*k;
    while (new_start < 0){
        new_start += n;
    }
    new_start = new_start % n;

    for (int i = 0; i < n; i++){
        if (row[i] != row[(i+new_start) % n]){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        for (int row = 0; row < mat.size(); row++){
            if (!rowShiftable(mat[row], k, -(row%2) * 2 + 1)){
                return false;
            }
        }
        return true;
    }
};


int main(){
    vector<vector<int>> test_inp = {{1,2,1,2},{5,5,5,5},{6,3,6,3}};
    int k = 2;
    bool target_res = true;
    Solution solver = Solution();
    bool res = solver.areSimilar(test_inp, k);

    if (res == target_res){
        printf("Test passed!\n");
    }
    else {
        printf("Test failed!\n");
    }
}