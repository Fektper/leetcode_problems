#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool end_smaller(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];
}

bool start_greater(const vector<int>& a, const vector<int>& b){
    return a[0] > b[0];
}

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
        map<int, int> max_before;

        
        sort(events.begin(), events.end(), end_smaller);
        int current_max = events[0][2];
        for (vector<int> event: events){
            current_max = max(current_max, event[2]);
            max_before[event[1]] = current_max;
        }

        int res = 0;
        int current_res = 0;
        std::map<int, int>::iterator before;
        for (vector<int> event: events){
            before = max_before.lower_bound(event[0]);

            while (before != max_before.begin() && before->first >= event[0]){
                before --;
            }
            if (before->first < event[0]){
                current_res = event[2] + before->second;
            } else {
                current_res = event[2];
            }
            res = max(res, current_res);
        }

        return res;

    }
};

int main(){
    vector<vector<int>> input = {{35,90,47},{72,80,70}};

    Solution solver = Solution();
    solver.maxTwoEvents(input);
}