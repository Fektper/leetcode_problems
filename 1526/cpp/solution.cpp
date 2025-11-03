#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

class MyMontonicIncreasingStack {
    private:
    vector<int> stack;

    public:
    int push(int x){
        if (this->stack.size() == 0){
            this->stack.push_back(x);
            return x;
        }
        int res = x > this->stack[this->stack.size() - 1] ? x : this->stack[this->stack.size() - 1];

        while (this->stack.size() > 0 && x < this->stack[this->stack.size() - 1]){
            this->stack.pop_back();
        }
        this->stack.push_back(x);
        return res;
    }

    int top(){
        return this->stack[this->stack.size()-1];
    }

    void pop(){
        if (this->stack.size() > 0){
            this->stack.pop_back();
        }
    }

    int size(){
        return this->stack.size();
    }
};

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        MyMontonicIncreasingStack monoS;

        monoS.push(target[0]);
        int res = 0;
        int current = 0;
        int drop = current;
        for (int i = 1; i < target.size(); i++){
            current = target[i];
            drop = monoS.push(current);
            res += (drop - current);
        }
        res += monoS.top();

        return res;
    }
};

int main(){
    vector<int> test = {1,2,3,2,1};
    test = {3, 1, 1, 2};
    Solution solver = Solution();
    printf("%d\n", solver.minNumberOperations(test));
}