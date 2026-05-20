#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> exists_map = vector<int>(n, 0);
        vector<int> res = vector<int>(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++){
            exists_map[A[i]-1]++;
            if (exists_map[A[i]-1] == 2){
                count++;
            }
            exists_map[B[i]-1]++;
            if (exists_map[B[i]-1] == 2){
                count++;
            }
            res[i] = count;
        }

        return res;

    }
};