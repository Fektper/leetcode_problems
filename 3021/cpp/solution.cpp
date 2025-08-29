#include <stdio.h>

using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {

        if (n == 1){
            return m / 2;
        }
        if (m == 1){
            return n / 2;
        }
        long long int big_n = n;
        long long int big_m = m;
        // Alice wins base config
        if ((n + m) % 2 == 1){
            return (big_n * big_m) / 2;
        }
        // Alice would lose base config, substract 1
        return flowerGame(n-1, m) + big_m/2;
    }
};


int main(){
    int test_n = 58280;
    int test_m = 69389;
    long long int target_res = 2021995460;

    Solution solver = Solution();
    long long int res = solver.flowerGame(test_n, test_m);

    if (res == target_res){
        printf("Test passed!\n");
    }
    else{
        printf("Test failed! Expected %lld but got %lld\n", target_res, res);
    }
}