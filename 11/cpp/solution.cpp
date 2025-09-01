#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int current_max_area = (j-i) * std::min(height[i], height[j]);
        int current_area;

        while (i < j){
            current_area = (j-i) * std::min(height[i], height[j]);
            if (current_area > current_max_area){
                current_max_area = current_area;
            }
            if (height[i] < height[j]){
                i++;
            }
            else {
                j--;
            }
        }
        return current_max_area;
    }
};