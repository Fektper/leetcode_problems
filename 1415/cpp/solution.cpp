#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

bool isHappy(vector<int>& alias){
    for (int i = 0; i < alias.size()-1; i++){
        if (alias[i] == alias[i+1]){
            return false;
        }
    }
    return true;
}

void addOne(vector<int>& alias){
    bool overflow = true;
    int i = alias.size() - 1;
    while (overflow){
        overflow = false;
        alias[i] = (alias[i] + 1) % 3;
        if (alias[i] == 0){
            overflow = true;
            i--;
        }
    }
}

class Solution {
public:
    string getHappyString(int n, int k) {
        int max_num = 3;
        for (int i = 1; i < n; i++){
            max_num = max_num*2;
        }
        if (max_num < k){
            return "";
        }
        
        vector<int> alias = vector<int>(n, 0);
        for (int i = 1; i < n; i+=2){
            alias[i] = 1;
        }
        int c = 1;
        while(c < k){
            addOne(alias);
            while (!isHappy(alias)){
                addOne(alias);
            }
            c++;
        }

        string res = string(n, 'a');
        for (int i = 0; i < n; i++){
            res[i] = 97 + alias[i];
        }
        return res;
    }
};

int main(){
    Solution solver = Solution();

    int n = 1;
    int k = 3;
    string target_res = "c";

    string res = solver.getHappyString(n, k);
    if (res == target_res){
        printf("Test passed!\n");
    }
    else{
        printf("Test failed!");
    }

}