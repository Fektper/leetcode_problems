#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> value_counts;
        int intermediate_res;
        for (int num: nums){
            intermediate_res = (value + (num % value)) % value;
            if (value_counts.find(intermediate_res) == value_counts.end()){
                value_counts[intermediate_res] = 1;
            }
            else {
                value_counts[intermediate_res] += 1;
            }
        }

        if (value_counts.find(0) == value_counts.end()){
            return 0;
        }

        int min_num = 0;
        int min_count = value_counts[0];

        for (int i = 1; i < value; i++){
            if (value_counts.find(i) == value_counts.end()){
                return i;
            }
            if (min_count > value_counts[i]){
                min_num = i;
                min_count = value_counts[i];
            }
        }

        return value * min_count + min_num;
    }
};