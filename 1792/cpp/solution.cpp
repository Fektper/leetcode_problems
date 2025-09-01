#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Compare{
public:
    bool operator() (tuple<int, double> a, tuple<int, double> b){
        return get<1>(a) < get<1>(b);
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<tuple<int, double>, vector<tuple<int, double>>, Compare> gains;

        double gain;
        for (int i = 0; i < classes.size(); i++){
            gain = ((double) classes[i][0] + 1) / ((double) classes[i][1] + 1) - ((double) classes[i][0]) / ((double) classes[i][1]);
            gains.push({i, gain});
        }

        tuple<int, double> current;
        int i;
        double new_gain;
        while (extraStudents > 0){
            current = gains.top();
            gains.pop();

            i = get<0>(current);
            classes[i][0]++;
            classes[i][1]++;
            new_gain = ((double) classes[i][0] + 1) / ((double) classes[i][1] + 1) - ((double) classes[i][0]) / ((double) classes[i][1]);
            
            gains.push({i, new_gain});
            extraStudents--;
        }

        double res = 0;
        for (int i = 0; i < classes.size(); i++){
            res += ((double) classes[i][0]) / ((double) classes[i][1]);
        }
        return res / classes.size();

    }
};