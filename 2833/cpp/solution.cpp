#include <string>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l_max = 0;
        int r_max = 0;
        int l_dist = 0;
        int r_dist = 0;

        for (char m: moves){
            switch (m){
                case 'L':
                    l_dist++;
                    r_dist--;
                    l_max = max(l_max, l_dist);
                    break;
                case 'R':
                    l_dist--;
                    r_dist++;
                    r_max = max(r_max, r_dist);
                    break;
                case '_':
                    l_dist++;
                    r_dist++;
                    l_max = max(l_max, l_dist);
                    r_max = max(r_max, r_dist);

            }
        }
        return max(r_dist, l_dist);
    }
};