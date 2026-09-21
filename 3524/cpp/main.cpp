#include <vector>

#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long int> res = vector<long long int>(k, 0);
        long long int prev_remainder = 0;
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if (i == j){
                    prev_remainder = nums[i] % k;
                    
                }
                else {
                    prev_remainder = (prev_remainder * nums[j]) % k;
                }
                
                for (int x = 0; x < k; x++){
                    if (prev_remainder == x) {
                        res[x]++;
                    }
                }
            }
        }



        return res;
    }
};

int main(){
    Solution sol = Solution();
    int k = 5;
    int n = 9999;
    
    vector<int> test_nums = vector<int>(n, 3);

    vector<long long int> res = sol.resultArray(test_nums, k);

}