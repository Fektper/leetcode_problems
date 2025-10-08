#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        long long int search_point;
        
        vector<int> res(spells.size(), 0);
        for (int i = 0; i < spells.size(); i++){
            search_point = (long long int) ceil((double) success / spells[i]);
            res[i] = distance(lower_bound(potions.begin(), potions.end(), search_point), potions.end());
        }
        return res;
    }
};