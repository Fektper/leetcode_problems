#include <vector>

using namespace std;

int findMinTakersAvailable(vector<vector<int>>& classes){

    double maxGain = -1;
    int idx = -1;

    double gain;
    for (int i = 0; i < classes.size(); i++){
        gain = ((double) classes[i][1] + 1) / ((double) classes[i][0] + 1) - ((double) classes[i][1]) / ((double) classes[i][0]);
        if (gain > maxGain){
            maxGain = gain;
            idx = i;
        }
    return idx;
}

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        int i;
        while (extraStudents > 0){
            i = findMinTakersAvailable(classes);
            classes[i][0]++;
            classes[i][1]++;
            extraStudents--;
        }

        double res = 0;
        for (int i = 0; i < classes.size(); i++){
            res += ((double) classes[i][0]) / ((double) classes[i][1]);
        }
        return res / classes.size();

    }
};