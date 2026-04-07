#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (n == 0){
            return "";
        }
        int cols = n / rows;

        string res;
        int idx;
        for (int i = 0; i < cols; i++){
            for (int pluser = 0; pluser < rows && (pluser + i) < cols; pluser++){
                idx = (i+pluser) + cols * pluser;
                res.push_back(encodedText[idx]);
    
                
            }

        }
        
        while (res[res.size()-1] == ' '){
            res.pop_back();
        }


        return res;
    }
};

int main(){
    string test = "a  b  ";
    int rows = 3;

    Solution solver = Solution();
    string res = solver.decodeCiphertext(test, rows);
    std::cout << res << "\n";
}