#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {

        vector<long long int> end_times(skill.size(), 0);
        vector<long long int> this_end_times(skill.size(), 0);
        long long int offset = 0;
        for (int i = 0; i < mana.size(); i++){

            this_end_times[0] = skill[0] * mana[i];
            offset = std::max(offset, end_times[0] - this_end_times[0] + skill[0] * mana[i]);
            for (int j = 1; j < skill.size(); j++){
                this_end_times[j] = this_end_times[j-1] + skill[j] * mana[i];
                offset = std::max(offset, end_times[j] - this_end_times[j] + skill[j] * mana[i]);
            }
            for (int j = 0; j < skill.size(); j++){
                end_times[j] = this_end_times[j] + offset;
            }
        }
        
        return end_times[end_times.size()-1];
    }
};

int main(){
    vector<int> skill = {1,5,2,4};
    vector<int> mana = {5,1,4,2};
    Solution solver = Solution();
    solver.minTime(skill, mana);
}