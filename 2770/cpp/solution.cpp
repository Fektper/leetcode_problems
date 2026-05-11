#include <vector>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res = vector<int>(n, 0);

        int a; int b;
        for (int j = 1; j < n; j++){
            a = nums[j];
            for (int i = 0; i < j; i++){
                b = nums[i];
                if (abs(a-b) <= target && (res[i] > 0 || i == 0)){
                    res[j] = max(res[j], res[i]+1);
                }
            }
        }

        return res[n-1] == 0 ? -1 : res[n-1];
    }
};

int main(){
    vector<int> inpt = {1, 3, 6, 4, 1, 2};
    int t = 2;
    Solution solver = Solution();
    printf("%d\n", solver.maximumJumps(inpt, t));
}