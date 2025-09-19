#include <vector>
#include <string>

using namespace std;

class Spreadsheet {
public:
    vector<vector<int>> grid;
    Spreadsheet(int rows) {
        this->grid = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        tuple<int, int> pos = getCellIndices(cell);
        this->grid[get<1>(pos)][get<0>(pos)] = value;
    }
    
    void resetCell(string cell) {
        tuple<int, int> pos = getCellIndices(cell);
        this->grid[get<1>(pos)][get<0>(pos)] = 0;
    }
    
    int getValue(string formula) {
        int sep_pos = formula.find('+');
        string cellOrValue1 = formula.substr(1, sep_pos-1);
        string cellOrValue2 = formula.substr(sep_pos+1, formula.size()-(sep_pos));

        int v1 = cellOrValue1[0] >= 65 ? getCell(cellOrValue1) : stoi(cellOrValue1);
        int v2 = cellOrValue2[0] >= 65 ? getCell(cellOrValue2) : stoi(cellOrValue2);
        return v1 + v2;
    }

    tuple<int, int> getCellIndices(string cell){
        // column, row
        tuple<int, int> result = {cell[0]-65, stoi(cell.substr(1, cell.size()-1))-1};
        return result;
    }

    int getCell(string cell){
        tuple<int, int> pos = getCellIndices(cell);
        return this->grid[get<1>(pos)][get<0>(pos)];
    }
};

int main(){
    Spreadsheet* obj = new Spreadsheet(24);
    obj->setCell("B24", 66688);
    obj->resetCell("O15");
}


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */