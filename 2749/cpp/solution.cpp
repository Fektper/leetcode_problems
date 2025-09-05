#include <vector>
#include <stdio.h>

using namespace std;

int num_of_bits_set_positive(long long int num){
    if (num < 0){
        return -1;
    }
    int count = 0;
    while (num > 0){
        count += 1 & num;
        num = num >> 1;
    }
    return count;
}

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long int new_target;
        long long int a = num1;
        long long int b = num2;

        for (int k = 0; k <= 60; k++){
            new_target = a - k*b;
            if (new_target < 0){
                return -1;
            }

            if (num_of_bits_set_positive(new_target) <= k && new_target >= k){
                return k;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> num1s = {3, 5};
    vector<int> num2s = {-2, 7};
    vector<int> target_results = {3, -1};

    Solution solver = Solution();

    for (int i = 0; i < num1s.size(); i++){
        int k = solver.makeTheIntegerZero(num1s[i], num2s[i]);
        if (k != target_results[i]){
            printf("Test failed! Expected %d but got %d\n", target_results[i], k);
        }
    }
}