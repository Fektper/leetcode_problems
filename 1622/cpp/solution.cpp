#include <vector>
#include <stdio.h>

using namespace std;


long long int multInv(long long int a, long long int p){
    long long int u, v, x1, x2, q, r, x;
    u = a;
    v = p;
    x1 = 1;
    x2 = 0;
    while (u != 1){
        q = v/u;
        r = v - q*u;
        x = x2 - q*x1;
        v = u;
        u = r;
        x2 = x1;
        x1 = x;
    }

    while (x1 < 0){
        x1 += p;
    }
    return x1;
}


class Fancy {
public:
    vector<int> values;
    long long int mult;
    long long int add;

    Fancy() {
        this->values = vector<int>();
        mult = 1;
        add = 0;
    }
    
    void append(int val) {
        long long int ins;
        if (val < this->add){
            ins = ((int)1e9+7) + val - this->add;
        } else{
            ins = val - this->add;
        }

        long long int mulInv = multInv(this->mult, 1e9 + 7);
        this->values.push_back((ins * mulInv) % ((int)1e9 + 7));

    }
    
    void addAll(int inc) {
        this->add = (this->add + inc) % ((int)1e9 + 7);
    }
    
    void multAll(int m) {
        this->mult = (this->mult * m) % ((int)1e9 + 7);
        this->add = (this->add * m) % ((int)1e9 + 7);
    }
    
    int getIndex(int idx) {
        if (idx >= values.size()){
            return -1;
        }
        long long int inter = (this->values[idx] * this->mult) % ((int)1e9 + 7);
        return (inter + this->add) % ((int)1e9 + 7);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

int main(){
    long long int t;
    Fancy obj = Fancy();
    obj.append(2);
    obj.addAll(3);
    t = obj.getIndex(0); // -> 5
    printf("t: %lld\n", t);

    obj.append(7);
    obj.multAll(2);
    t = obj.getIndex(0); // -> 10
    printf("t: %lld\n", t);
    t = obj.getIndex(1); // -> 14
    printf("t: %lld\n", t);

    obj.addAll(3);
    obj.append(10);
    obj.multAll(2);

    t = obj.getIndex(0); // 26
    printf("t: %lld\n", t);
    t = obj.getIndex(1); // 34
    printf("t: %lld\n", t);
    t = obj.getIndex(2); // 20
    printf("t: %lld\n", t);
}