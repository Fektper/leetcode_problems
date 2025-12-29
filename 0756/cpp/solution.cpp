#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>


using namespace std;


vector<string> allPosibleStackings(string& row, unordered_map<string, vector<char>>& mappings){
    vector<string> res;

    
    for (int i = 0; i < row.size()-1; i++){
        if (mappings.find(row.substr(i, 2)) == mappings.end()){
            return {};
        }
    }

    vector<string> current_res = {""};
    vector<string> new_res;
    for (int i = 0; i < row.size()-1; i++){
        new_res = {};
        for (char c: mappings[row.substr(i, 2)]){
            for (string cur: current_res){
                new_res.push_back(cur + c);
            }
        }
        current_res = new_res;
    }

    return current_res;
}

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mappings;
        string first;
        char second;
        for (string mapping: allowed){
            second = mapping[2];
            first = mapping.substr(0, 2);

            if (mappings.find(first) != mappings.end()){
                mappings[first].push_back(second);
            }
            else {
                mappings[first] = {second};
            }
        }

        vector<string> base_queue;
        // priority_queue<string, vector<string>, StringSizeSort> base_queue;
        unordered_set<string> checked;
        base_queue.push_back(bottom);

        vector<string> new_rows = {};

        while (base_queue.size() > 0){
            bottom = base_queue[base_queue.size() - 1];
            base_queue.pop_back();
            if (bottom.size() == 1){
                return true;
            }

            new_rows = allPosibleStackings(bottom, mappings);
            // std::cout << new_rows.size() << "\n";
            for (string row: new_rows){
                if (checked.find(row) == checked.end()){
                    base_queue.push_back(row);
                    checked.insert(row);
                }
                
            }

        }

        return false;
    }
};

int main(){
    string bottom = "AFFFFA";
    vector<string> mappings = {"ADA","ADC","ADB","AEA","AEC","AEB","AFA","AFC","AFB","CDA","CDC","CDB","CEA","CEC","CEB","CFA","CFC","CFB","BDA","BDC","BDB","BEA","BEC","BEB","BFA","BFC","BFB","DAA","DAC","DAB","DCA","DCC","DCB","DBA","DBC","DBB","EAA","EAC","EAB","ECA","ECC","ECB","EBA","EBC","EBB","FAA","FAC","FAB","FCA","FCC","FCB","FBA","FBC","FBB","DDA","DDC","DDB","DEA","DEC","DEB","DFA","DFC","DFB","EDA","EDC","EDB","EEA","EEC","EEB","EFA","EFC","EFB","FDA","FDC","FDB","FEA","FEC","FEB","FFA","FFC","FFB","DDD","DDE","DDF","DED","DEE","DEF","DFD","DFE","DFF","EDD","EDE","EDF","EED","EEE","EEF","EFD","EFE","EFF","FDD","FDE","FDF","FED","FEE","FEF","FFD","FFE","FFF"};
    Solution solver = Solution();
    solver.pyramidTransition(bottom, mappings);
}