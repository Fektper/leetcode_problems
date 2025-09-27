#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

double triangleArea(vector<int>& a, vector<int>& b, vector<int>& c){
    // Area = (1/2) * |x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)|

    double A = 0.5 * abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1]- b[1]));
    return A;
    // double g = sqrt( pow((a[0] - b[0]), 2) + pow((a[1] - b[1]), 2) );

    // vector<double> h_vec = {(double) a[1] - b[1], (double) b[0] - a[0]};
    // double h_vec_norm = sqrt(pow(h_vec[0], 2) + pow(h_vec[1], 2));
    // h_vec[0] = h_vec[0] / h_vec_norm;
    // h_vec[1] = h_vec[1] / h_vec_norm;

    // double h = abs(h_vec[0] * (c[0]-a[0]) + h_vec[1] * (c[1]-a[1]));

    // return g*h/2;
}

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double largest = 0;
        double current;
        for (int i = 0; i < points.size()-2; i++){
            for (int j = i+1; j < points.size()-1; j++){
                for (int k = j+1; k < points.size(); k++){
                    current = triangleArea(points[i], points[j], points[k]);
                    if (current > largest){
                        largest = current;
                    }
                }
            }
        }
        return largest;
    }
};


int main(){
    vector<vector<int>> test = {{4,6},{6,5},{3,1}};
    Solution solver = Solution();
    std::cout << solver.largestTriangleArea(test) << std::endl;
}