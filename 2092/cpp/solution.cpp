#include <vector>
#include <algorithm>

using namespace std;

bool meeting_compare(vector<int>& a, vector<int>& b){
    return a[2] < b[2];
}

int getLastIndex(int time, vector<vector<int>>& meetings, int start){
    for (int i = start; i < meetings.size(); i++){
        if (meetings[i][2] != time){
            return i-1;
        }
    }
    return meetings.size() - 1;
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true;
        
        sort(meetings.begin(), meetings.end(), meeting_compare);

        int this_meeting_time = 0;
        int first_index = 0;
        int last_index;
        bool change;

        while (first_index < meetings.size()){
            change = true;
            this_meeting_time = meetings[first_index][2];
            last_index = getLastIndex(meetings[first_index][2], meetings, first_index);

            while (change){
                change = false;
                for (int i = first_index; i <= last_index; i++){
                    if (( knows[meetings[i][0]] && !knows[meetings[i][1]] ) || ( !knows[meetings[i][0]] && knows[meetings[i][1]] ) ){
                        change=true;
                        knows[meetings[i][0]] = true;
                        knows[meetings[i][1]] = true;
                    }
                }
            }

            first_index = last_index + 1;
        }


        vector<int> res;
        for (int i = 0; i < n; i++){
            if (knows[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    int n = 6;
    vector<vector<int>> meetings = {{1,2,5},{2,3,8},{1,5,10}};
    int first = 1;

    Solution solver = Solution();
    solver.findAllPeople(n, meetings, first);
}