using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int totalDrank = 0;

        while (numBottles > 0){
            totalDrank += numBottles;
            emptyBottles += numBottles;
            numBottles = emptyBottles / numExchange;
            emptyBottles = emptyBottles % numExchange;
        }

        return totalDrank;
    }
};