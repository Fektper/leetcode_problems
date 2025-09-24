#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>

using namespace std;


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long int num = (long long int) numerator;
        long long int denom = (long long int) denominator;
        if (num == 0){
            return to_string(0);
        }
        int sign = 1;
        if (num < 0){
            num = -num;
            sign = -sign;
        }
        if (denom < 0){
            denom = -denom;
            sign = -sign;
        }
        long long int pre_decimal = num / denom;
        long long int rest = (num - pre_decimal*denom)*10;

        int recurrence_index = -1;
        unordered_map<int, int> positions;
        vector<int> decimals;
        int i = 0;
        while (rest > 0){
            if (positions.count(rest)){
                // We had this denominator already
                recurrence_index = positions[rest];
                break;
            }
            positions[rest] = i;

            if (rest < denom){
                rest = rest*10;
                decimals.push_back(0);
            } else {
                decimals.push_back(rest / denom);
                rest = (rest % denom)*10;
            }
            i++;
        }

        string res;
        if (sign == 1){
            res = to_string(pre_decimal);
        }
        else {
            res = "-";
            res.append(to_string(pre_decimal));
        }

        // No decimal part
        if (decimals.size() == 0){
            return res;
        }

        res.push_back('.');

        // Decimal but no recurrence
        if (recurrence_index == -1){
            for (int dec: decimals){
                res.push_back(dec + 48);
            }
            return res;
        }

        // With recurrence (parantheses)
        for (int i = 0; i < recurrence_index; i++){
            res.push_back(decimals[i] + 48);
        }
        res.push_back('(');
        for (int i = recurrence_index; i < decimals.size(); i++){
            res.push_back(decimals[i]+48);
        }
        res.push_back(')');
        return res;
    }
};

int main(){
    Solution solver = Solution();

    std::cout << solver.fractionToDecimal(1, 2) << std::endl;

    std::cout << solver.fractionToDecimal(2, 1) << std::endl;

    std::cout << solver.fractionToDecimal(4, 333) << std::endl;

    std::cout << solver.fractionToDecimal(4, 3) << std::endl;

    std::cout << solver.fractionToDecimal(10, 9) << std::endl;

    std::cout << solver.fractionToDecimal(23, 999) << std::endl;

    std::cout << solver.fractionToDecimal(41, 333) << std::endl;

    std::cout << solver.fractionToDecimal(0, 333) << std::endl;

    std::cout << solver.fractionToDecimal(-50, 8) << std::endl;

    std::cout << solver.fractionToDecimal(-50, -8) << std::endl;

    std::cout << solver.fractionToDecimal(50, -8) << std::endl;

    std::cout << solver.fractionToDecimal(0, -2020123123) << std::endl;
}