#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

bool lexiko_smaller(string& a, string& b){
    for (int i = 0; i < a.size(); i++){
        if (a[i] < b[i]){
            return true;
        }
        if (a[i] > b[i]){
            return false;
        }
    }
    return false;
}

string add_uneven(string& s, int num){
    string res(s);
    for (int i = 1; i < s.size(); i += 2){
        res[i] = ((s[i] -48 + num) % 10 ) + 48;
    }
    return res;
}

string shift_string(string& s, int num){
    string res(s);
    for (int i = 0; i < s.size(); i++){
        res[(i+num) % s.size()] = s[i];
    }
    return res;
}

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> checked;
        queue<string> next_queue;
        string smallest = s;
        checked.insert(s);
        next_queue.push(s);

        string shifted;
        string added;
        string current;
        while(next_queue.size() > 0){
            current = next_queue.front();
            next_queue.pop();

            added = add_uneven(current, a);
            shifted = shift_string(current, b);

            if (checked.find(added) == checked.end()){
                checked.insert(added);
                next_queue.push(added);
                if (lexiko_smaller(added, smallest)){
                    smallest = added;
                }
            }
            if (checked.find(shifted) == checked.end()){
                checked.insert(shifted);
                next_queue.push(shifted);
                if (lexiko_smaller(shifted, smallest)){
                    smallest = shifted;
                }
            }
        }
        return smallest;
    }
};

int main(){
    Solution solver = Solution();
    solver.findLexSmallestString("01010101010101010", 1, 1);
}