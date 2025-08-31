#include <string>

using namespace std;


void romanNumLogic(string& str, int num, char ten, char five, char one){
    if (num == 0){
        return;
    }
    if (num == 9 || num == 4){
        str.push_back(one);
        str.push_back(num == 9 ? ten : five);
        return;
    }
    else if (num >= 5){
        str.push_back(five);
        num -= 5;
    }
    for (int i = 0; i < num; i++){
        str.push_back(one);
    }
}


class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        
        int thousands = num / 1000;
        num = num % 1000;
        int hundreds = num / 100;
        num = num % 100;
        int tens = num / 10;
        num = num % 10;
        int ones = num;

        for (int i = 0; i < thousands; i++){
            res.push_back('M');
        }
        romanNumLogic(res, hundreds, 'M', 'D', 'C');
        romanNumLogic(res, tens, 'C', 'L', 'X');
        romanNumLogic(res, ones, 'X', 'V', 'I');
        return res;
    }
};