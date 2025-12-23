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
        map<int, int> max_after;

        
        sort(events.begin(), events.end(), end_smaller);
        int last_max = events[0][2];
        for (vector<int> event: events){
            last_max = max(event[2], last_max);
            max_before[event[1]] = last_max;
            // max_before.insert({event[1], last_max});
        }

        sort(events.begin(), events.end(), start_greater);
        last_max = events[0][2];
        for (vector<int> event: events){
            last_max = max(event[2], last_max);
            max_after[event[0]] = last_max;
            // max_after.insert({event[0], last_max});
        }

        int res = 0;
        int current_res = 0;
        int after = 0;
        for (vector<int> event: events){
            
            auto after = max_after.upper_bound(event[1]);
            if (after != max_after.end()){
                current_res = after->second + event[2];
            } else {
                current_res = event[2];
            }

            auto before = max_before.begin();
            before = max_before.lower_bound(event[0]);
            while (before != max_before.begin() && before->first >= event[0]){
                before--;
            }
            if (before->first < event[0]){
                current_res = max(current_res, before->second + event[2]);
            }

            res = max(res, current_res);
        }

        return res;


    }
};

int main(){
    vector<vector<int>> input = {{1,3,2},{4,5,2},{1,5,5}};

    Solution solver = Solution();
    solver.maxTwoEvents(input);
}