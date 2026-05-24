#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class IndexValCompare{
public:
    const bool operator()(tuple<int, int>& a, tuple<int, int>& b){
        return get<1>(a) < get<1>(b);
    }
};

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<tuple<int, int>> index_and_values;
        vector<int> jumps = vector<int>(n, 0);

        for (int i = 0; i < n; i++){
            index_and_values.push_back({i, arr[i]});
        }

        sort(index_and_values.begin(), index_and_values.end(), IndexValCompare());
        int val; int i;
        for (tuple<int, int> cur : index_and_values){
            i = get<0>(cur);
            val = get<1>(cur);
            int max_val = 0;
            for (int j = i-1; j >= 0 && j >= i-d; j--){
                if (arr[j] >= val){
                    break;
                }
                max_val = max(max_val, jumps[j]);
            }
            for (int j = i+1; j < n && j <= i+d; j++){
                if (arr[j] >= val){
                    break;
                }
                max_val = max(max_val, jumps[j]);
            }
            jumps[i] = 1+ max_val;
        }


        return *max_element(jumps.begin(), jumps.end());

    }
};

int main(){
    vector<int> test_inpt = {6,4,14,6,8,13,9,7,10,6,12};
    Solution solver = Solution();
    solver.maxJumps(test_inpt, 2);
}