#include <string>

using namespace std;

bool stringDivides(string big, string divider){
    if (big.size() % divider.size() != 0){
        return false;
    }

    int n = divider.size();

    for (int i = 0; i < big.size() / n; i++){
        for (int j = 0; j < n; j++){
            if (big[i*n + j] != divider[j]){
                return false;
            }
        }
    }
    return true;
}

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int max_gcd_len;
        int n = str1.size();
        int m = str2.size();
        for (int i = 1; i <= std::min(n, m); i++){
            if (n % i == 0 && m % i == 0){
                max_gcd_len = i;
            }
        }

        for (int i = max_gcd_len; i > 0; i--){
            if (n % i != 0 || m % i != 0){
                continue;
            }
            string candidate = str1.substr(0, i);
            if (candidate.compare(str2.substr(0, i)) == 0){
                if (stringDivides(str1, candidate) && stringDivides(str2, candidate)){
                    return candidate;
                }
            }
        }
        return "";
    }
};