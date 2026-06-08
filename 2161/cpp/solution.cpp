#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int num_smaller = 0;
        int num_equal = 0;
        int n = nums.size();

        vector<int> res = vector<int>(n, 0);

        for (int num: nums){
            if (num == pivot){
                num_equal++;
            }
            else if (num < pivot){
                num_smaller++;
            }
        }
        int i_small = 0;
        int i_eq = num_smaller;
        int i_g = num_smaller+num_equal;

        for (int num: nums){
            if (num < pivot){
                res[i_small] = num;
                i_small++;
            }
            else if (num == pivot){
                res[i_eq] = num;
                i_eq++;
            }
            else {
                res[i_g] = num;
                i_g++;
            }
        }
        return res;
    }
};