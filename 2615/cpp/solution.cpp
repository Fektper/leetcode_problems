#include <vector>
#include <unordered_map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> num_indices;

        for (int i = 0; i < nums.size(); i++){
            if (num_indices.find(nums[i]) == num_indices.end()){
                num_indices[nums[i]] = {i};
            }
            else {
                num_indices[nums[i]].push_back(i);
            }
        }
        vector<long long int> res = vector<long long int>(nums.size(), 0);

        long long int pre;
        long long int post;
        long long int n_pre;
        long long int n_post;
        for (auto num_idx: num_indices){
            pre = 0; post = 0; n_pre = 0; n_post=0;
            vector<int>& idx = num_idx.second;
            n_post = idx.size();
            for (int i: idx){
                post += i;
            }
            for (int i: idx){
                res[i] = n_pre * i - pre + post - n_post * i;
                n_post -= 1;
                post -= i;
                pre += i;
                n_pre += 1;
            }
        }

        return res;
    }
};

int main(){
    vector<int> test = vector<int>(100000, 20);
    // 5, 0, 3, 3, 0
    Solution solver = Solution();
    
}