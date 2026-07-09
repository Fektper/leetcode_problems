#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> breaks;
        for (int i = 1; i < n; i++){
            if (nums[i] - nums[i-1] > maxDiff){
                breaks.push_back(i);
            }
        }

        vector<bool> res = vector<bool>(queries.size(), false);

        for (int i = 0; i < queries.size(); i++){
            if(upper_bound(breaks.begin(), breaks.end(), queries[i][0]) == upper_bound(breaks.begin(), breaks.end(), queries[i][1])){
                res[i] = true;
            }
        }
        return res;
    }
};