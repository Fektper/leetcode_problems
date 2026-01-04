#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int num){
    int valid_primes[67] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331};

    if (binary_search(valid_primes, valid_primes+67, num)){
        return true;
    }

    for (int div:  valid_primes){
        if (div >= num){
            return true;
        }
        if (num % div == 0){
            return false;
        }
    }
    return true;
}

int getFourDivisorSum(int num){
    //vector<int>
    int valid_primes[67] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331};

    int prime_a = 0;
    int candidate_b = 0;

    int current;
    for (int div: valid_primes){
        if (div >= num){
            break;
        }

        if (num % div == 0){
            prime_a  = div;
            candidate_b = num / div;
            if (candidate_b == 1 || prime_a == candidate_b){
                candidate_b = 0;
                break;
            }
            else if (isPrime(candidate_b) || candidate_b  == prime_a*prime_a){
                break;
            }
            else {
                candidate_b = 0;
                break;
            }
        }

    }

    if (prime_a == 0 || candidate_b == 0){
        return 0;
    }
    return 1 + num + prime_a +  candidate_b;
}

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int num: nums){
            res += getFourDivisorSum(num);
        }
        return res;
    }
};