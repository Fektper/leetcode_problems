#include <vector>

using namespace std;

long long int num_combs(int n){
    long long int res = 0;
    while (n > 0){
        res += n;
        n--;
    }
    return res;
}

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long int res = 0;

        int i = 0;
        int j = 0;
        int current = prices[0];
        while (i < prices.size()){
            current = prices[i];
            j = 1;
            while (i + j < prices.size() && prices[i+j] +1 == prices[i+j-1]){
                j++;
            }
            res += num_combs(j);
            i += j;
        }
        return res;
    }
};


int main(){
    vector<int> prices = {3, 2, 1, 4};
    Solution solver = Solution();
    solver.getDescentPeriods(prices);
}