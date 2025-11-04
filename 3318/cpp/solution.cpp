#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

struct ElementOccurence{
    int ele;
    int count;
};

class ElementOrder{
    public:
    bool operator() (const ElementOccurence& a, const ElementOccurence& b) const {
        if (a.count > b.count){
            return true;
        }
        else if (a.count == b.count){
            return a.ele > b.ele;
        }
        return false;
    }
};

int x_sum(set<ElementOccurence, ElementOrder>& occurence_set, int num_eles){
    int res = 0;
    auto it = occurence_set.begin();
    for (int i = 0; i < num_eles; i++){
        if (it != occurence_set.end()){
            res += it->count * it->ele;
            it = next(it);
        }
        else {
            break;
        }
        
    }
    return res;
}

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int res_length = nums.size() - k + 1;
        vector<int> res = vector<int>(res_length, 0);

        unordered_map<int, int> element_occurences;
        set<ElementOccurence, ElementOrder> occurence_set;

        for (int i = 0; i < k; i++){
            if (element_occurences.find(nums[i]) != element_occurences.end()){
                element_occurences[nums[i]]++;
            }
            else {
                element_occurences.insert({nums[i], 1});
            }
        }

        for (auto x: element_occurences){
            occurence_set.insert({x.first, x.second});
        }

        int this_res;
        int rem; int ins;

        for (int i = 0; i < res_length; i++){
            res[i] = x_sum(occurence_set, x);

            if (i < res_length - 1){
                rem = nums[i];
                ins = nums[i+k];

                
                occurence_set.erase({rem, element_occurences[rem]});
                element_occurences[rem]--;
                if (element_occurences[rem] > 0){
                    occurence_set.insert({rem, element_occurences[rem]});
                }
                

                occurence_set.erase({ins, element_occurences[ins]});
                element_occurences[ins]++;
                occurence_set.insert({ins, element_occurences[ins]});
            }
        }


        return res;
    }
};

int main(){
    vector<int> nums = {1,1,2,2,3,4,2,3};
    int k = 6; int x = 2;

    Solution solver = Solution();
    solver.findXSum(nums, k, x);
}