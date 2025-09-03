#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;


class Smaller{
public:
    bool operator() (tuple<int, int> a, tuple<int, int> b){
        return get<0>(a) < get<0>(b);
    }
};
class Greater{
public:
    bool operator() (tuple<int, int> a, tuple<int, int> b){
        return get<0>(a) > get<0>(b);
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, Smaller> high_elements;
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, Greater> low_elements;
        for (int i = 0; i < nums.size(); i++){
            high_elements.push({nums[i], i});
            low_elements.push({nums[i], i});
        }

        tuple<int, int> first;
        tuple<int, int> second;
        while (!high_elements.empty() && !low_elements.empty()){
            first = high_elements.top();
            second = low_elements.top();
            if (get<0>(first) + get<0>(second) > target){
                high_elements.pop();
            }
            else if (get<0>(first) + get<0>(second) > target){
                low_elements.pop();
            }
            else if (get<1>(first) == get<1>(second)){
                low_elements.pop();
            }
            else {
                return {get<1>(first), get<1>(second)};
            }
        }
        return {0,0};
    }
};