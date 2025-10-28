#include <vector>

using namespace std;

bool runSimulation(int currentPos, int dir, vector<int> nums){
    // startPos is 0 is assumed!

    while (currentPos >= 0 && currentPos < nums.size()){
        if (nums[currentPos] == 0){
            currentPos += dir;
        }
        else {
            nums[currentPos]--;
            dir *= -1;
            currentPos += dir;
        }
    }

    for (int num: nums){
        if (num != 0){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int res_count = 0;
        vector<int> dirs = {-1, 1};
        for (int startPos = 0; startPos < nums.size(); startPos++){
            if (nums[startPos] == 0){
                for (int dir: dirs){
                    if (runSimulation(startPos, dir, nums)){
                        res_count++;
                    }
                }
            }
        }
        return res_count;
    }
};

int main(){
    Solution solver = Solution();
    vector<int> test = {1, 0, 2, 0, 3};
    solver.countValidSelections(test);
}