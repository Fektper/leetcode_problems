#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int i = 0;
        int begin;
        char curr;
        int mx;
        while (i < colors.size()){
            curr = colors[i];
            mx = neededTime[i];
            res += neededTime[i];
            while (i+1 < colors.size() && colors[i+1] == curr){
                i++;
                res += neededTime[i];
                mx = max(mx, neededTime[i]);
            }
            res -= mx;
            i++;
        }
        return res;
    }
};