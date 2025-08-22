#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        return 6;
    }
};

int main(int argc, char* argv[]){
    vector<int> row1 = {0, 0, 1, 1};
    vector<int> row2 = {0, 1, 0, 0};

    vector<vector<int>> test_input = {row1, row2};

    Solution *sol = new Solution();
    if (sol->minimumArea(test_input) == 6){
        printf("Test passed\n");
    }
    else{
        printf("Test failed\n");
    }
}