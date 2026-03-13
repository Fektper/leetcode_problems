#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

struct WorkerTime{
    long long int time;
    int worker;
};
class CompareWorkerTimesGreater{
public:
    bool operator() (WorkerTime a, WorkerTime b){
        return a.time > b.time;
    }
};

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long int solution = 0;

        priority_queue<WorkerTime, vector<WorkerTime>, CompareWorkerTimesGreater> timesQueue;
        vector<long long int> times_taken = vector<long long int>(workerTimes.size(), 1);
        vector<long long int> work_times = vector<long long int>(workerTimes.size(), 0);

        for (int i = 0; i < workerTimes.size(); i++){
            timesQueue.push({workerTimes[i], i});
        }
        
        WorkerTime this_time;
        for (int i = mountainHeight; i > 0; i--){
            this_time = timesQueue.top();
            timesQueue.pop();

            solution = max(this_time.time, solution);

            times_taken[this_time.worker] += 1;
            work_times[this_time.worker] = this_time.time;

            timesQueue.push({this_time.time + times_taken[this_time.worker] * workerTimes[this_time.worker], 
                this_time.worker});
        }

        return solution;
    }
};

int main(){
    Solution solver = Solution();
    int height = 5;
    vector<int> times = {1};
    long long int target_res = 1+2+3+4+5;
    long long int res = solver.minNumberOfSeconds(height, times);
    if (res == target_res){
        printf("Test passed\n");
    }
    else {
        printf("Test failed. Expected %lld but got %lld\n", target_res, res);
    }
}