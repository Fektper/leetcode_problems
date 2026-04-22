#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;

        int n;
        int dist = 0;
        for (string query: queries){
            n = query.size();
            for (string dict: dictionary){
                if (dict.size() != n) {
                    continue;
                }
                dist = 0;
                for (int i = 0; i < n; i++){
                    if (query[i] != dict[i]){
                        dist++;
                    }
                    if (dist > 2){
                        break;
                    }
                }
                if (dist <= 2){
                    res.push_back(query);
                    break;
                }
            }
        }
        return res;
    }
};