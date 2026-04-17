#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

int reversed(int a){
    int res = 0;
    while (a > 0){
        res *= 10;
        res += a% 10;
        a = a/10;
    }
    return res;
}

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> last_index_of;
        int rev;
        int min_dist = __INT32_MAX__;
        for (int i = 0; i < n; i++){
            if (last_index_of.find(nums[i]) != last_index_of.end()){
                min_dist = min(min_dist, i - last_index_of[nums[i]]);
            }
            last_index_of[reversed(nums[i])] = i;
        }

        return min_dist == __INT32_MAX__ ? -1 : min_dist;
    }
};

int main(){
    vector<int> tests = {50, 1234, 90343200, 12300};
    for (int t: tests){
        printf("%d -> %d\n", t, reversed(t));
    }
}