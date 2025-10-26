#include <vector>

using namespace std;

class Bank {
public:
    vector<long long> balances;
    Bank(vector<long long>& balance) {
        this->balances = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > 0 && account1 <= balances.size() && account2 > 0 && account2 <= balances.size()){
            if (this->balances[account1-1] >= money){
                this->balances[account1-1] -= money;
                this->balances[account2-1] += money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (account > 0 && account <= balances.size()){
            this->balances[account - 1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if (account > 0 && account <= balances.size()){
            if (this->balances[account - 1] >= money){
                this->balances[account - 1] -= money;
                return true;
            }

            return false;
        }
        return false;
    }
};