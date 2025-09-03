#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = "";
        int prefix_index = 0;
        char current;
        while(true){
            if (strs[0].size() <= prefix_index){
                break;
            }
            current = strs[0][prefix_index];
            for (int i = 1; i < n; i++){
                if(strs[i].size() <= prefix_index || strs[i][prefix_index] != current){
                    return prefix;
                }
            }
            prefix.push_back(current);
            prefix_index++;
        }
        return prefix;
    }
};


int main(){
    vector<string> strs = {"flower","flow","flight"};
    Solution solver = Solution();
    std::cout << solver.longestCommonPrefix(strs) << std::endl;
}