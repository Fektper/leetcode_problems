#include <vector>


using namespace std;

int maxIndex(vector<double>& vals){
    int idx = 0;
    double maxVal = vals[0];

    for (int i = 1; i < vals.size(); i++){
        if (vals[i] > maxVal){
            maxVal = vals[i];
            idx = i;
        }
    }
    return idx;
}

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        vector<double> gains(classes.size());

        for (int i = 0; i < classes.size(); i++){
            gains[i] = ((double) classes[i][0] + 1) / ((double) classes[i][1] + 1) - ((double) classes[i][0]) / ((double) classes[i][1]);
        }

        int i;
        while (extraStudents > 0){
            i = maxIndex(gains);
            classes[i][0]++;
            classes[i][1]++;
            extraStudents--;
            gains[i] = ((double) classes[i][0] + 1) / ((double) classes[i][1] + 1) - ((double) classes[i][0]) / ((double) classes[i][1]);
        }

        double res = 0;
        for (int i = 0; i < classes.size(); i++){
            res += ((double) classes[i][0]) / ((double) classes[i][1]);
        }
        return res / classes.size();

    }
};