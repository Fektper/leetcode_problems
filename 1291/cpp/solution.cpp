#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<vector<int>> sequentials = {{}};
        for (int ten = 1; ten <= 8; ten++){
            sequentials[0].push_back(ten*10 + ten+1);
        }

        long long int pows[] = {1, 10, 100, 1000, 10000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
        int max_digis = 0;
        while (high > pows[max_digis]){
            max_digis++;
        }

        for (int d = 3; d <= max_digis; d++){
            vector<int> news = {};
            int last_digit = 0;
            for (int x: sequentials[d-3]){
                last_digit = x % 10;
                if (last_digit == 9){
                    continue;
                }
                news.push_back(x*10 + last_digit+1);
            }
            sequentials.push_back(news);
        }

        vector<int> res = {};
        bool early_break = false;
        for (vector<int> seqs: sequentials){
            for (int x: seqs){
                if (x > high){
                    return res;
                }
                if (x >= low){
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};