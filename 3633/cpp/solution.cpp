#include <vector>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int earliest_land_end = INT32_MAX;
        for (int i = 0; i < landStartTime.size(); i++){
            earliest_land_end = min(landStartTime[i] + landDuration[i], earliest_land_end);
        }

        int earliest_water_end = INT32_MAX;
        for (int i = 0; i < waterStartTime.size(); i++){
            earliest_water_end = min(waterStartTime[i] + waterDuration[i], earliest_water_end);
        }

        int min_duration = INT32_MAX;
        for (int i = 0; i < landStartTime.size(); i++){
            min_duration = min(min_duration, max(landStartTime[i], earliest_water_end) + landDuration[i]);
        }

        for (int i = 0; i < waterStartTime.size(); i++){
            min_duration = min(min_duration, max(waterStartTime[i], earliest_land_end) + waterDuration[i]);
        }
        return min_duration;
    }
};