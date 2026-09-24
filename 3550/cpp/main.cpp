int digitSum(int num){
    int res = 0;
    while (num > 0) {
        res += num % 10;
        num = num / 10;
    }
    return res;
}

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (digitSum(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};
