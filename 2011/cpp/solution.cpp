#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (string op: operations){
            if (op[0] == '+' || op[2] == '+'){
                x++;
            }
            else {
                x--;
            }
        }
        return x;
    }
};