#include <vector>

using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ar1 = {nums[0]};
        vector<int> ar2 = {nums[1]};

        for (int i = 2; i < nums.size(); i++){
            if (ar1[ar1.size() - 1] > ar2[ar2.size()-1]){
                ar1.push_back(nums[i]);
            }
            else {
                ar2.push_back(nums[i]);
            }
        }

        ar1.insert(ar1.end(), ar2.begin(), ar2.end());
        return ar1;
    }
};

int main(){
    vector<int> test = {2,1,3};
    Solution solver = Solution();
    solver.resultArray(test);
}