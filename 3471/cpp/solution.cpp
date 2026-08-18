#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int cand1 = nums[0];
        int cand2 = nums[n-1];
        
        if (k == n){
            return *max_element(nums.begin(), nums.end());
        }

        if (k == 1){
            sort(nums.begin(), nums.end(), std::greater<int>());
            int i = 0;
            for (int i = 0; i < n; i++){
                if (i - 1 >= 0 && nums[i-1] == nums[i]){
                    continue;
                }
                if (i +1 <= n-1 && nums[i+1] == nums[i]){
                    continue;
                }
                return nums[i];
            }
            return -1;
        }
        
        if (cand1 == cand2){
            return -1;
        }

        bool c1 = true;
        bool c2 = true;

        for (int i = 1; i < n-1; i++){
            if (nums[i] == cand1){
                c1 = false;
            }
            if (nums[i] == cand2){
                c2 = false;
            }
        }
        if (c1 && c2){
            return max(cand1, cand2);
        }
        if (c1){
            return cand1;
        }
        if (c2) {
            return cand2;
        }
        return -1;
    }
};

int main(){
    Solution solver = Solution();
    vector<int> test = {0, 0};
    solver.largestInteger(test, 1);
}