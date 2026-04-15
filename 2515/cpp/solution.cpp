#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int low; int high;

        for (int i = 0; i < n/2 + 1; i++){
            low = (startIndex + n - i) % n;
            high = (startIndex + i) % n;
            if (words[low].compare(target) == 0 || words[high].compare(target) == 0){
                return i;
            }
        }
        return -1;
    }
};