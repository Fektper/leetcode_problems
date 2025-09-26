#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> lastValidIndex;
        int resCount = 0;

        int start = 0;
        while (start < nums.size() && nums[start] == 0){
            start++;
        }

        int greaterThan;
        int lastIndex;
        for (int i = start; i < ((int) nums.size()) -2; i++){
            for (int j = i+1; j < ((int) nums.size()) - 1; j++){
                greaterThan = nums[i] + nums[j] - 1;

                if (lastValidIndex.find(greaterThan) != lastValidIndex.end()){
                    lastIndex = lastValidIndex[greaterThan];
                }
                else {
                    lastIndex = (int) distance(nums.begin(), upper_bound(nums.begin(), nums.end(), greaterThan)) - 1;
                   lastValidIndex[greaterThan] = lastIndex;
                }
                resCount += lastIndex - j;
            }
        }
        


        return resCount;

    }
};

int main(){
    Solution solver = Solution();
    vector<int> test = {2, 2, 3, 4};
    solver.triangleNumber(test);
    test = {1};
    solver.triangleNumber(test);
    test = {0};
    solver.triangleNumber(test);
}