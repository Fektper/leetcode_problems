#include <limits.h>

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
        bool leading = true;
        int this_digit;
        int result = 0;
        while (x > 0){
            this_digit = x % 10;
            x = x/10;
            
            if (leading && this_digit == 0){
                continue;
            }

            leading = false;
            if ((INT_MAX - this_digit) / 10 < result){
                return 0;
            }
            result *= 10;
            result += this_digit;
        }

        return sign * result;
    }
};