#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        vector<int> parts_v1 = getParts(version1);
        vector<int> parts_v2 = getParts(version2);

        int i = 0;
        while (i < min(parts_v1.size(), parts_v2.size())){
            if (parts_v1[i] > parts_v2[i]){
                return 1;
            }
            else if (parts_v1[i] < parts_v2[i]){
                return -1;
            }
            i++;
        }

        vector<int>& current = parts_v1.size() > parts_v2.size() ? parts_v1 : parts_v2;
        int fac = parts_v1.size() > parts_v2.size() ? 1 : -1;

        for (int j = i; j < current.size(); j++){
            if (current[j] > 0){
                return fac;
            }
        }
        return 0;
    }

    vector<int> getParts(string& version){
        vector<int> res;

        int i = 0;
        int end_i;
        string sub_v;
        int zero_count = 0;
        while (i < version.size()){
            end_i = min(version.size(), version.find('.', i));
            sub_v = version.substr(i, end_i-i);

            zero_count = 0;
            while (zero_count < sub_v.size() -1 && sub_v[zero_count] == '0'){
                zero_count++;
            }

            res.push_back(stoi(sub_v.substr(zero_count, sub_v.size()-zero_count)));
            i = end_i+1;
        }

        return res;
    }
};

int main(){
    Solution solver = Solution();

    std::cout << solver.compareVersion("1.2", "1.10") << std::endl; // -1

    std::cout << solver.compareVersion("1.01", "1.001") << std::endl; // 0

    std::cout << solver.compareVersion("1.01.0.0000000.000.0", "1.001") << std::endl; // 0

    std::cout << solver.compareVersion("1.001.000.000.0.1.000", "1.01") << std::endl; // 1
}