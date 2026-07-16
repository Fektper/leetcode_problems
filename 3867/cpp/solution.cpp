#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if (a == b){
        return a;
    }
    int big = max(a, b);
    int div = min(a, b);
    int rem = big % div;
    while (rem != 0){
        big = div;
        div = rem;
        rem = big % div;
    }
    return div;
}


class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_gcd = vector<int>(n, 0);
        int mx = nums[0];
        for (int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            prefix_gcd[i] = gcd(nums[i], mx);
        }

        sort(prefix_gcd.begin(), prefix_gcd.end());
        long long int res = 0;
        for (int i = 0; i < n/2; i++){
            res += gcd(prefix_gcd[i], prefix_gcd[n-i-1]);
        }
        return res;
    }
};