
using namespace std;

int calc_digit_product(int m){
    if (m == 0){
        return 0;
    }
    int digit_prod = 1;
    while (m > 0){
        digit_prod *= m % 10;
        m = m/10;
    }
    return digit_prod;
}

class Solution {
public:
    int smallestNumber(int n, int t) {
        int digit_sum = calc_digit_product(n);
        while ((digit_sum / t) * t != digit_sum){
            n++;
            digit_sum = calc_digit_product(n);
        }
        return n;
    }
};