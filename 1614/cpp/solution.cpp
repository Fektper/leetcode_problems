
#include <string>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int max_depth = 0;
        for (char c: s){
            switch (c) {
                case '(':
                    depth++;
                    max_depth = max(max_depth, depth);
                    break;
                case ')':
                    depth--;
                    break;
                default:
                    break;
            }
        }

        return max_depth;
    }
};