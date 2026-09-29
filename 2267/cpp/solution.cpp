#include <vector>

using namespace std;

void combineVectorsWithAdd(vector<int>& a, vector<int>& b, vector<int>& res, int add, int max){
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()){
        if (a[i] < b[j]){
            if (a[i] + add >= 0 && a[i] + add <= max){
                res.push_back(a[i] + add);
            }
            i++;
        }
        else if (b[j] < a[i]){
            if (b[j] + add >= 0 && b[j] + add <= max){
                res.push_back(b[j] + add);
            }
            j++;
        }
        else {
            if (a[i] + add >= 0 && a[i] + add <= max){
                res.push_back(a[i] + add);
            }
            i++;
            j++;
        }
    }
    while (i < a.size()){
        if (a[i] + add >= 0 && a[i] + add <= max){
            res.push_back(a[i] + add);
        }
        i++;
    }
    while (j < b.size()){
        if (b[j] + add >= 0 && b[j] + add <= max){
            res.push_back(b[j] + add);
        }
        j++;
    }
    return;
}

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if ((rows + cols -1) % 2 == 1) {
            return false;
        }
        vector<vector<vector<int>>> pathNums = vector<vector<vector<int>>>(rows, vector<vector<int>>(cols, vector<int>()));
        
        if (grid[0][0] == '('){
            pathNums[0][0] = {1};
        } else {
            return false;
            // pathNums[0][0] = {};
        }

        // Init first row and col
        for (int col = 1; col < cols; col++){
            if (pathNums[0][col-1].size() > 0){
                int res = pathNums[0][col-1][0] + (grid[0][col] == '(' ? 1: -1);
                if (res >= 0) {
                    pathNums[0][col] = {res};
                }
            }
        }
        for (int row = 1; row < rows; row++){
            if (pathNums[row-1][0].size() > 0){
                int res = pathNums[row-1][0][0] + (grid[row][0] == '(' ? 1: -1);
                if (res >= 0) {
                    pathNums[row][0] = {res};
                }
            }
        }

        for (int row = 1; row < rows; row++){
            for (int col = 1; col < cols; col++){
                combineVectorsWithAdd(pathNums[row-1][col], pathNums[row][col-1], pathNums[row][col], grid[row][col] == '(' ? 1 : -1, rows - row - 1 + cols - col - 1);
            }
        }

        if (pathNums[rows-1][cols-1].size() > 0){
            return pathNums[rows-1][cols-1][0] == 0;
        }
        return false;
    }
};

int main(){
    vector<vector<char>> test = {{'(','(','('},{')','(',')'},{'(','(',')'},{'(','(',')'}};

    Solution solution = Solution();

    printf("%d", solution.hasValidPath(test));
}