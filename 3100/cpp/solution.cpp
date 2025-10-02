class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = 0;
        int empty_count = 0;
        while (numBottles > 0){
            drank += numBottles;
            empty_count += numBottles;
            numBottles = 0;

            while (empty_count >= numExchange){
                numBottles++;
                empty_count -= numExchange;
                numExchange++;
            }
        }
        return drank;
    }
};