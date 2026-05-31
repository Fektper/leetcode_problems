#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long int real_mass = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int asteroid: asteroids){
            if (asteroid <= real_mass){
                real_mass += asteroid;
            }
            else {
                return false;
            }
        }
        return true;
    }
};