#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<vector<int>> intervals;

        int i = 0;
        int begin;
        char curr;
        while (i < colors.size()){
            curr = colors[i];
            begin = i;
            while (i+1 < colors.size() && colors[i+1] == curr){
                i++;
            }
            if (i != begin){
                intervals.push_back({begin, i});
            }

            i++;
        }

        int res = 0;
        for (vector<int> intv: intervals){
            res -= *max_element(neededTime.begin() + intv[0], neededTime.begin() + intv[1] + 1);
            for (int i = intv[0]; i <= intv[1]; i++){
                res += neededTime[i];
            }
        }
        return res;
    }
};