#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode> children;
    int shortestChildIndex = 0;
    int shortestChildLength = __INT32_MAX__;
};

int findLongestPrefixMatch(TrieNode& node, string& s, int offset){
    if (s.size() <= offset){
        return node.shortestChildIndex;
    }
    char last = s[s.size() - 1 - offset];
    if (node.children.find(last) == node.children.end()){
        return node.shortestChildIndex;
    }
    return findLongestPrefixMatch(node.children[last], s, offset+1);
}

void insertWord(TrieNode& node, string& s, int depth, int maxDepth, int i){
    if (s.size() < node.shortestChildLength){
        node.shortestChildIndex = i;
        node.shortestChildLength = s.size();
    }

    if (s.size() - depth > 0 && depth <= maxDepth){
        char last = s[s.size() - 1 - depth];
        if (node.children.find(last) == node.children.end()){
            node.children[last] = {};
        }
        insertWord(node.children[last], s, depth+1, maxDepth, i);
    }
}

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int maxDepth = 0;
        for (string word: wordsQuery){
            maxDepth = max(maxDepth, (int)word.size());
        }
        TrieNode rootNode;
        for (int i = 0; i < wordsContainer.size(); i++){
            string word = wordsContainer[i];
            insertWord(rootNode, word, 0, maxDepth, i);
        }

        vector<int> res = vector<int>(wordsQuery.size(), 0);
        for (int i = 0; i < wordsQuery.size(); i++){
            res[i] = findLongestPrefixMatch(rootNode, wordsQuery[i], 0);
        }
        return res;
    }
};

int main(){
    vector<string> container = {"abcd","bcd","xbcd"};
    vector<string> querys = {"cd","bcd","xyz"};

    Solution solver = Solution();
    solver.stringIndices(container, querys);
}



