#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> digit_counts;
        int tmp;
        int i;
        bool balanced = false;
        n++;
        while(true){
            digit_counts = {0,0,0,0,0,0,0,0,0,0};
            i = 0;
            tmp = n;

            while (tmp > 0){
                digit_counts[tmp % 10] += 1;
                tmp = tmp / 10;
                i++;
            }

            balanced = true;
            for (int i = 0; i <= 9; i++){
                if (digit_counts[i] != 0 && digit_counts[i] != i){
                    balanced = false;
                    break;
                }
            }
            if (balanced){
                return n;
            }

            if (n / (int)pow(10, i-1) > i){
                n = pow(10, i);
            } else {
                n++;
            }
        }
    }
};