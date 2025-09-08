#include <vector>

using namespace std;

bool noZero(int num){

    int rest;
    while (num > 0){
        rest = num % 10;
        if (rest == 0){
            return false;
        }
        num = num/10;
    }
    return true;

}

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res(2);
        int a; int b;
        for (int i = 1; i <= n/2; i++){
            a = i;
            b = n-a;
            if (noZero(a) && noZero(b)){
                res[0] = a;
                res[1] = b;
                return res;
            }
        }
        res[0] = 1;
        res[1] = n-1;
        return res;
    }
};