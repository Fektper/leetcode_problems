#include <vector>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxCount = 0;
        int maxAmount = 0;
        vector<int> counts(100, 0);
        for (int num: nums){
            counts[num-1]++;
            if (counts[num-1] > maxCount){
                maxCount = counts[num-1];
                maxAmount = 1;
            }
            else if (counts[num-1] == maxCount){
                maxAmount++;
            }
        }

        return maxCount*maxAmount;
    }
};