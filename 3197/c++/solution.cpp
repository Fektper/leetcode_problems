#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        return 3;
    }
};



int main(){
    int target_sol = 5;
    vector<int> row1 = {1,0,1,0};
    vector<int> row2 =  {0,1,0,1};
    vector<vector<int>> test_input = {row1, row2};

    Solution* solver = new Solution();
    int res = solver->minimumSum(test_input);

    if (res == target_sol){
        printf("Test passed!\n");
    }
    else{
        printf("Test failed! Expected %d but got %d\n", target_sol, res);
    }
}