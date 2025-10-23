#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> nums = vector<int>(s.size());
        for (int i = 0; i < s.size(); i++){
            nums[i] = s[i] - 48;
        }

        int size = nums.size();

        while (size > 2){
            for (int i = 0; i < size -1; i++){
                nums[i] = (nums[i] + nums[i+1] ) % 10;
            }

            size = size-1;
        }

        return nums[0] == nums[1];
    }
};