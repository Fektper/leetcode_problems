#include <vector>
#include <unordered_map>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, int> smallest_row;
        unordered_map<int, int> biggest_row;
        unordered_map<int, int> smallest_col;
        unordered_map<int, int> biggest_col;

        int x; int y;
        for (vector<int> building: buildings){
            x = building[0];
            y = building[1];

            if (smallest_row.find(y) == smallest_row.end()){
                smallest_row[y] = x;
                biggest_row[y] = x;
            }
            else {
                smallest_row[y]  = min(smallest_row[y], x);
                biggest_row[y]  = max(biggest_row[y], x);
            }

            if (smallest_col.find(x) == smallest_col.end()){
                smallest_col[x] = y;
                biggest_col[x] = y;
            }
            else {
                smallest_col[x] = min(smallest_col[x], y);

                biggest_col[x] = max(biggest_col[x], y);
            }
        }

        int res = 0;
        for (vector<int> building: buildings){
            x = building[0];
            y = building[1];

            if (smallest_row[y] < x && biggest_row[y] > x && smallest_col[x] < y && biggest_col[x] > y){
                res++;
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> test_in = {{2,4},{1,2},{2,1},{3,1},{1,4},{2,2},{3,2},{1,3}};
    Solution solver = Solution();
    solver.countCoveredBuildings(4, test_in);
}