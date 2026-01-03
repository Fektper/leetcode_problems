#include <vector>

using namespace std;

enum Color {
    RED,
    YELLOW,
    GREEN
};

bool transitionAllowed(vector<Color> &before, vector<Color> &after){
    for (int i = 0; i < 3; i++){
        if (before[i] == after[i]){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    int numOfWays(int n) {
        vector<vector<Color>> states = {
            {RED, YELLOW, RED},
            {RED, YELLOW, GREEN},
            {RED, GREEN, RED},
            {RED, GREEN, YELLOW},
            {YELLOW, RED, YELLOW},
            {YELLOW, RED, GREEN},
            {YELLOW, GREEN, RED},
            {YELLOW, GREEN, YELLOW},
            {GREEN, RED, YELLOW},
            {GREEN, RED, GREEN},
            {GREEN, YELLOW, RED},
            {GREEN, YELLOW, GREEN}
        };

        vector<vector<int>> transitions(12, vector<int>());

        for (int i = 0; i < states.size(); i++){
            for (int j = 0; j < states.size(); j++){
                if (transitionAllowed(states[j], states[i])){
                    transitions[i].push_back(j);
                }
            }
        }

        vector<long long int> current = vector<long long int>(12, 1);
        vector<long long int> next = vector<long long int>(12, 0);

        for (int epoch = 1; epoch < n; epoch++){
            for (int i = 0; i < 12; i++){
                for (int j: transitions[i]){
                    next[i] = (next[i] + current[j]) % (1000000000 + 7);
                }
            }

            
            
            // Copy state to current
            for (int i = 0; i < 12; i++){
                current[i] = next[i];
                next[i] = 0;
            }

        }



        int res = 0;

        for (long long int val: current){
            res = (val + res) % (1000000000 + 7);
        }

        return res;
    }
};