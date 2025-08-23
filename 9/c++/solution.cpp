#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }

        vector<int> digits(0);
        while (x > 0){
            digits.push_back(x % 10);
            x = x /10;
        }

        int digi_num = digits.size();

        for (int i = 0; i < digi_num / 2; i++){
            if (digits.at(i) != digits.at(digi_num - 1 - i)){
                return false;
            }
        }
        return true;
    }
};

int main(){
    int test_input = 121;
    bool wanted_result = true;

    Solution* solver = new Solution();

    if (solver->isPalindrome(test_input) == wanted_result){
        printf("Test passed\n");
    }
    else{
        printf("Test failed\n");
    }
}