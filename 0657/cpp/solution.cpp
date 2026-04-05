#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();

        if (n % 2 == 1){
            return false;
        }

        int l = 0;
        int u = 0;
        for (char move: moves){
            switch (move)
            {
            case 'L':
                l++;
                break;
            case 'R':
                l--;
                break;
            case 'U':
                u++;
                break;
            case 'D':
                u--;
                break;
            default:
                break;
            }
        }
        return (l == 0) && (u == 0);
        
    }
};