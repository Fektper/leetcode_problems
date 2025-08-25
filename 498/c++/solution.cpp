#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(); // rows
        int n = mat.at(0).size(); // cols

        int max_diagonal_index = m-1 + n-1;

        vector<int> res(m*n);
        int res_index = 0;

        for (int diagonal_index = 0; diagonal_index <= max_diagonal_index; diagonal_index++){
            int row, col, col_add, row_dif, col_dif;
            if (diagonal_index % 2 == 0){
                row = diagonal_index;
                if (row >= m){
                    row_dif = row - m + 1;
                    row = m - 1;
                } else{
                    row_dif = 0;
                }
                col = row_dif;
                col_add = 1;
            }
            else {
                col = diagonal_index;
                if (col >= n){
                    col_dif = col - n + 1;
                    col = n-1;
                } else{
                    col_dif = 0;
                }
                row = col_dif;
                col_add = -1;
            }

            while (0 <= col && col < n && 0 <= row && row < m){
                res.at(res_index) = mat.at(row).at(col);
                col += col_add;
                row -= col_add;
                res_index++;
            }

        }
        return res;
    }
};



int main(){
    vector<int> row1 = {1, 2, 3}; // [[1,2,3],[4,5,6],[7,8,9]]
    vector<int> row2 = {4, 5, 6};
    vector<int> row3 = {7, 8, 9};
    vector<vector<int>> test_input = {row1, row2, row3};
    vector<int> target_solution = {1,2,4,7,5,3,6,8,9};


    Solution* solver = new Solution();
    vector<int> res = solver->findDiagonalOrder(test_input);

    bool correct = res.size() == target_solution.size();

    for (int i = 0; i < std::min(res.size(), target_solution.size()); i++){
        if (target_solution.at(i) != res.at(i)){
            correct = false;
        }
    }

    for(int i: res){
        printf("%d, ", i);
    }
    printf("\n");

    if (correct){
        printf("Test passed!\n");
    }
    else{
        printf("Test failed!\n");
    }
}