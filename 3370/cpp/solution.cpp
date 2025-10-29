using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int i = 0;
        while (n >> 1 > 0){
            i++;
            n = n >> 1;
        }

        int res = 1;
        for (int j = 0; j < i; j++){
            res = res <<1;
            res++;
        }
        return res;
    }
};