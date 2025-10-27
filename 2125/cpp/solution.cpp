#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        int prev = 0;

        for (string row: bank){
            int count = 0;
            for (char c: row){
                if (c == '1'){
                    count++;
                }
            }

            res += count * prev;
            if (count > 0){
                prev = count;
            }
            
        }
        return res;
    }
};

int main(){
    Solution sol = Solution();
    vector<string> test = {"0"};
    sol.numberOfBeams(test);
}