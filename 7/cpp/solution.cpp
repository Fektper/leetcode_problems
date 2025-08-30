#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x == INT_MIN){
            return 0;
        }
        if (x < 0){
            sign = -1;
            x = -x;
        }

        // x is positive or zero
        vector<int> digits(0);
        int this_digit;
        while (x > 0){
            this_digit = x % 10;
            digits.push_back(this_digit);
            x = x/10;
        }

        int ptr = 0;
        // Skip leading zeros
        while (ptr < digits.size() && digits[ptr] == 0){
            ptr++;
        }
        // Skip 0;
        if (ptr == digits.size()){
            return 0;
        }
        int result = 0;
        while (ptr < digits.size()){
            this_digit = digits[ptr];

            if ((INT_MAX - this_digit) / 10 < result){
                return 0;
            }
            result *= 10;
            result += this_digit;
            ptr++;
        }

        return sign * result;

    }
};