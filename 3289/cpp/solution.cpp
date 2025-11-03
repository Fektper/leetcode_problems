#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        vector<int> seen(100, 0);

        for (int num: nums){
            if (seen[num] > 0){
                res.push_back(num);
            }
            else {
                seen[num]++;
            }
        }
        return res;
    }
};
