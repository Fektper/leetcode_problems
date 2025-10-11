#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>

using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<long long int, long long int> damageCounts;

        for (int powr: power){
            if (damageCounts.find(powr) == damageCounts.end()){
                damageCounts[powr] = 1;
            }
            else {
                damageCounts[powr] += 1;
            }
        }

        vector<long long int> dp(1, 0);
        vector<int> previousDamages(1, -2);
        int j = 0;
        int i = 1;
        int max_j=0;
        for(auto it = damageCounts.begin(); it != damageCounts.end(); it++){
            j = i-1;
            while (previousDamages[j] + 2 >= it->first){
                j--;
            }

            max_j = j;
            j = j-1;
            while (j >= 0 && i-j <= 10){
                if (dp[j] > dp[max_j]){
                    max_j = j;
                }
                j--;
            }
            j = max_j;
            dp.push_back(dp[j] + it->first * it->second);
            previousDamages.push_back(it->first);
            i++;

        }

        if (dp.size() == 1){
            return dp[0];
        }
        if (dp.size() == 2){
            return max(dp[0], dp[1]);
        }

        return max(max(dp[dp.size()-1], dp[dp.size()-2]), dp[dp.size()-3]);


    }
};

int main(){
    vector<int> inpt = {3,4,5,6,6,7,1,1,1,1,1,9,9,9,9,9,9,9,9,9,6};
    Solution solver = Solution();

    printf("%d\n", solver.maximumTotalDamage(inpt));
}