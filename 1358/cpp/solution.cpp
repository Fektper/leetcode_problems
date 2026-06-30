#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> a_idxs;
        vector<int> b_idxs;
        vector<int> c_idxs;
        
        for (int i = 0; i < n; i++){
            if (s[i] == 'a'){
                a_idxs.push_back(i);
            }
            else if (s[i] == 'b'){
                b_idxs.push_back(i);
            }
            else {
                c_idxs.push_back(i);
            }
        }

        vector<int>::iterator i_a;
        vector<int>::iterator i_b;
        vector<int>::iterator i_c;

        int res = 0;
        

        for (int i = 0; i < n; i++){
            i_a = lower_bound(a_idxs.begin(), a_idxs.end(), i);
            i_b = lower_bound(b_idxs.begin(), b_idxs.end(), i);
            i_c = lower_bound(c_idxs.begin(), c_idxs.end(), i);
            if (i_a == a_idxs.end() || i_b == b_idxs.end() || i_c == c_idxs.end()){
                break;
            }
            int min_end = max(*i_a, max(*i_b, *i_c));
            res += n - min_end; 
        }

        return res;
    }
};