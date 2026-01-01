#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;

        int i = digits.size() - 1;

        while (i >= 0 && carry){
            digits[i] = (digits[i] + 1) % 10;
            carry = digits[i] == 0;
            i--;
        }
        
        if (carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};