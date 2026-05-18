#include <stdio.h>

#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> jump_map;
        queue<int> next_item_queue;

        for (int i = 0; i < n; i++){
            if (jump_map.find(arr[i]) == jump_map.end()){
                jump_map[arr[i]] = {i};
            }
            else {
                jump_map[arr[i]].push_back(i);
            }
        }

        vector<int> distances = vector<int>(n, __INT32_MAX__);
        distances[0] = 0;
        next_item_queue.push(0);
        int i;
        while (!next_item_queue.empty() && distances[n-1] == __INT32_MAX__){
            i = next_item_queue.front();
            next_item_queue.pop();
            if (i-1 > 0 && distances[i-1] == __INT32_MAX__){
                distances[i-1] = distances[i]+1;
                next_item_queue.push(i-1);
            }
            if (i+1 < n && distances[i+1] == __INT32_MAX__){
                distances[i+1] = distances[i]+1;
                next_item_queue.push(i+1);
            }
            for (int j: jump_map[arr[i]]){
                if (distances[j] == __INT32_MAX__){
                    distances[j] = distances[i] + 1;
                    next_item_queue.push(j);
                }
            }
            jump_map[arr[i]] = {};
        }

        return distances[n-1];
    }
};

int main(){
    vector<int> test = {100,-23,-23,404,100,23,23,23,3,404};
    Solution solver = Solution();
    printf("Res: %d\n", solver.minJumps(test));
}