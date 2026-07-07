using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long int digit_sum = 0;
        long long int res = 0;
        long long int mult = 1;

        while (n > 0){
            int digit = n % 10;
            n = n / 10;
            if (digit == 0){
                continue;
            }
            
            digit_sum += digit;
            res += digit * mult;
            if (n > 0){
                mult *= 10; // Just in case to prevent potential mult overflow on last digit
            }
        }

        return res * digit_sum;
    }
};