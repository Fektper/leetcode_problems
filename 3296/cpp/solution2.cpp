#include <vector>
#include <stdio.h>

using namespace std;

bool isSolvableIn(long long int t, int height, vector<int>& workerTimes){
    int i = 0;
    while (height > 0 && i < workerTimes.size()){
        long long int j = 1;
        long long int total_time = 0;
        while(total_time + j * workerTimes[i] <= t){
            height--;
            total_time += j * workerTimes[i];
            j++;
        }
        i++;
    }
    return height <= 0;
}

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long int solution = 0;

        long long int low = 0;
        long long int high = 1;
        while (!isSolvableIn(high, mountainHeight, workerTimes)){
            low = high;
            high = high*2;
        }
        
        long long int mid;
        while (high > low){
            mid = (high + low) / 2;
            if (isSolvableIn(mid, mountainHeight, workerTimes)){
                high = mid;
            }
            else {
                low = mid+1;
            }
        }

        return high;
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