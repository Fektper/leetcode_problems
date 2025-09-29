#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int minTriangulation(vector<int>& values, int start, int end, unordered_map<int, int>& lookup){
    int lookup_num = start + end*1000;
    if (lookup.find(lookup_num) != lookup.end()){
        return lookup[lookup_num];
    }

    if (end-start < 2){
        return 0;
    }

    int totalMin = INT32_MAX;
    int currentMin;

    for (int k = start+1; k < end; k++){
        currentMin = values[start] * values[end] * values[k] + minTriangulation(values, start, k, lookup) + minTriangulation(values, k, end, lookup);
        if (currentMin < totalMin){
            totalMin = currentMin;
        }
    }
    lookup[lookup_num] = totalMin;
    return totalMin;
}

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        unordered_map<int, int> lookup;
        return minTriangulation(values, 0, values.size()-1, lookup);
    }
};

int main(){
    vector<int> testInput = {3, 7, 4, 5};
    Solution solver = Solution();

    std::cout << solver.minScoreTriangulation(testInput) << std::endl;
}