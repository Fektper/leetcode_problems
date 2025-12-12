#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool customSmaller(vector<string>& a, vector<string>& b){
    if (stoi(a[1]) < stoi(b[1])){
        return true;
    }
    else if (stoi(a[1]) == stoi(b[1])){
        if (a[0] == "OFFLINE" && b[0] != "OFFLINE"){
            return true;
        } else{
            return false;
        }
    }
    else {
        return false;
    }
}

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), customSmaller);

        vector<int> onlineCounts = vector<int>(numberOfUsers, 0);
        vector<int> mentionCounts = vector<int>(numberOfUsers, 0);
        int lastTime = stoi(events[0][1]);
        int thisTime = 0;
        for (vector<string> event: events){
            thisTime = stoi(event[1]);
            // Update online status
            for (int i = 0; i < numberOfUsers; i++){
                if (onlineCounts[i] > 0){
                    onlineCounts[i] -= thisTime-lastTime;
                }
            }
            lastTime = thisTime;

            // Handle offline
            if (event[0] == "OFFLINE"){
                onlineCounts[stoi(event[2])] = 60;
            }
            // Handle mentions
            else {
                if (event[2] == "ALL"){
                    for (int i = 0; i < numberOfUsers; i++){
                        mentionCounts[i]++;
                    }
                }
                else if (event[2] == "HERE"){
                    for (int i = 0; i < numberOfUsers; i++){
                        if (onlineCounts[i] <= 0){
                            mentionCounts[i]++;
                        }
                    }
                }
                else {
                    int start = 0;
                    int end = 0;
                    while (end < event[2].size() && start < event[2].size()){
                        while (end < event[2].size() && event[2][end] != ' '){
                            end++;
                        }
                        string sub = event[2].substr(start+2, end-(start+2));
                        mentionCounts[stoi(sub)] += 1;
                        start = end+1;
                        end = start;
                    }
                }
            }

        }


        return mentionCounts;
    }
};

int main(){
    vector<vector<string>> events = {{"MESSAGE","5","HERE"},{"OFFLINE","10","0"},{"MESSAGE","15","HERE"},{"OFFLINE","18","2"},{"MESSAGE","20","HERE"}};

    Solution solver = Solution();

    solver.countMentions(3, events);
}