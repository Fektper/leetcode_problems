#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_squared_diagonal = 0;
        int max_area = 0;

        int squared_diagonal = 0;
        for (int i = 0; i < dimensions.size(); i++){
            squared_diagonal = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
            if (squared_diagonal > max_squared_diagonal){
                max_squared_diagonal = squared_diagonal;
                max_area = dimensions[i][0] * dimensions[i][1];
            }
            else{
                if (squared_diagonal == max_squared_diagonal && dimensions[i][0] * dimensions[i][1] > max_area){
                    max_area = dimensions[i][0] * dimensions[i][1];
                }
            }
        }
        return max_area;
    }
};

int main(){
    vector<int> row1 = {9, 3};
    vector<int> row2 = {8, 6};
    vector<vector<int>> test_input = {row1, row2};
    int test_result = 8*6;

    Solution solver = Solution();
    if (solver.areaOfMaxDiagonal(test_input) == test_result){
        printf("Test passed\n");
    }
    else{
        printf("Test failed\n");
    }

}