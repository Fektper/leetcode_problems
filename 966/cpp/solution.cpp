#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool isVowel(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return true;
    }
    return false;
}


string getBestQueryMatch(string query, vector<string>& wordlist){
    string capitalizationMatch = "";
    string vowelMatch = "";
    bool capMatch; bool vowelErrorMatch; bool identicalMatch;
    for (string candidate: wordlist){
        if (candidate.size() != query.size()){
            continue;
        }
        capMatch = true; vowelErrorMatch = true; identicalMatch = true;
        for (int i = 0; i < candidate.size(); i++){
            if (candidate[i] != query[i]){
                identicalMatch = false;

                if (candidate[i]-32 != query[i] && candidate[i] != query[i]-32){
                    capMatch = false;
                    if (!isVowel(candidate[i]) || !isVowel(query[i])){
                        vowelErrorMatch = false;
                    }
                }
            }
        }

        if (identicalMatch){
            return candidate;
        }
        if (capMatch && capitalizationMatch == ""){
            capitalizationMatch = candidate;
        }
        if (vowelErrorMatch && vowelMatch == ""){
            vowelMatch = candidate;
        }
    }
    if (capitalizationMatch != ""){
        return capitalizationMatch;
    }
    return vowelMatch;
}

string getNoVowelWord(string word){
    string result = "";
    for (char c: word){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            continue;
        }
        else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            continue;
        }
        result.push_back(c >= 97 ? c - 32 : c);
    }
    return result;
}

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> results(queries.size());
        unordered_map<string, vector<string>> noVowelMap;

        string noVowelWord;
        unordered_map<string, vector<string>>::iterator findResult;
        for (string correctWord: wordlist){
            noVowelWord = getNoVowelWord(correctWord);
            findResult = noVowelMap.find(noVowelWord);
            if (findResult == noVowelMap.end()){
                noVowelMap.insert({noVowelWord, {correctWord}});
            }
            else{
                findResult->second.push_back(correctWord);
            }
        }

        string query;
        for (int i = 0; i < queries.size(); i++){
            query = queries[i];
            findResult = noVowelMap.find(getNoVowelWord(query));
            if (findResult == noVowelMap.end()){
                results[i] = "";
            }
            else{
                results[i] = getBestQueryMatch(query, findResult->second);
            }
        }

        return results;
    }
};

int main(){
    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> querys = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};

    Solution solver = Solution();
    solver.spellchecker(wordlist, querys);
}