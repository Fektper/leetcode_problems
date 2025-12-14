#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        
        int seat_count = 0;
        for (char c: corridor){
            if (c == 'S'){
                seat_count++;
            }
        }
        if (seat_count < 2 || seat_count % 2 != 0){
            return 0;
        }

        // There exists atleastt 1 valid solution
        // Find split points
        vector<long long int> numPlacementOptions;
        int i = 0;
        int j = 0;
        int current_seat_count = 0;

        while (i < corridor.size()){
            if (corridor[i] == 'S'){
                if (current_seat_count == 2){
                    current_seat_count = 1;
                }
                else {
                    current_seat_count = (current_seat_count + 1) % 3;
                }
            }
            else if (current_seat_count != 2){

            }
            else {
                while (i+j < corridor.size() && corridor[i+j] == 'P'){
                    j++;
                }
                if (i+j != corridor.size()){
                    // If plants till end, we cant place divider
                    numPlacementOptions.push_back(j+1);
                }

                i += j;
                current_seat_count = 0;
                j=0;
                continue;
            }
            i++;
        }

        long long int res = 1;
        for (long long int p: numPlacementOptions){
            res = (res*p) % (1000000007) ;
        }

        return (int) res;

    }
};

int main(){
    string inpt = "PSPSPPPSSSSPSSPSSPSPPSSSPPSPSPPPSSSPSPPSSSPSSSPPSPPPSPSPPPSPSPPSSPPSSPSPSSPPPPPSPSPSSSPSSSSPPPSPSPPS";
    Solution solver = Solution();
    printf("%d\n", solver.numberOfWays(inpt));
}