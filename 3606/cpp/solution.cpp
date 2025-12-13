#include <vector>
#include <string>

#include <algorithm>

using namespace std;

struct Coupon{
    string code;
    string businessLine;
    bool isActive;

    bool operator< (Coupon& b){
        if (this->businessLine.compare(b.businessLine) < 0){
            return true;
        }
        else if (this->businessLine.compare(b.businessLine) == 0){
            return this->code.compare(b.code) < 0;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<Coupon> coupons;
        for (int i = 0; i < code.size(); i++){
            if (!isActive[i]){
                continue;
            }
            if (businessLine[i] != "electronics" && businessLine[i] != "grocery" && businessLine[i] != "pharmacy" && businessLine[i] != "restaurant"){
                continue;
            }

            bool nameValid = code[i].size() > 0;
            int j = 0;
            while (nameValid && j < code[i].size()){
                if (code[i][j] >= 65 && code[i][j] <= 90){
                }
                else if (code[i][j] >= 97 && code[i][j] <= 122){
                }
                else if (code[i][j] >= 48 && code[i][j] <= 57){
                }
                else if (code[i][j] == '_'){
                    
                }
                else {
                    nameValid = false;
                }
                j++;
            }

            if (!nameValid){
                continue;
            }

            coupons.push_back({code[i], businessLine[i], isActive[i]});
        }
        sort(coupons.begin(), coupons.end());

        vector<string> res;
        for (Coupon coup: coupons){
            res.push_back(coup.code);
        }

        return res;
    }
};


int main(){
    vector<string> codes = {"SAVE20","","PHARMA5","SAVE@20"};
    vector<string> businessLine = {"restaurant","grocery","pharmacy","restaurant"};
    vector<bool> isActive = {true, true, true, true};

    Solution solver = Solution();
    solver.validateCoupons(codes, businessLine, isActive);
}