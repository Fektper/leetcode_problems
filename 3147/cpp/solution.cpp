#include <vector>

using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int max_energy = -__INT32_MAX__ - 1;
        int current_energy;
        for (int i = energy.size() - 1; i >= 0; i--){
            current_energy = energy[i];
            if (i + k < energy.size()){
                current_energy += energy[i+k];
                energy[i] = current_energy;
            }
            if (current_energy > max_energy){
                max_energy = current_energy;
            }
        }
        return max_energy;
    }
};