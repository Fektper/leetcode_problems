#include <vector>
#include <list>
using namespace std;

class LinkedList{
public:
    int value;
    LinkedList* prev;
    LinkedList* next;
    LinkedList(int val){
        this->value = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
    LinkedList(int val, LinkedList* next, LinkedList* prev){
        this->value = val;
        this->next = next;
        this->prev = prev;
    }
};

long long int gcd_euclid(long long int a, long long int b){
    while (a >1 && b > 1){
        if (a==b){
            return a;
        }
        if (a > b){ // Improvement: substract b as many times as necessary to make a <= b
            a = a-b;
        }
        else if (a < b){
            b = b-a;
        }
    }
    return 1;
}


class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        LinkedList* head = new LinkedList(nums[0]);
        LinkedList* current = head;
        LinkedList* next;
        for (int i = 1; i < nums.size(); i++){
            next = new LinkedList(nums[i], nullptr, current);
            current->next = next;
            current = next;
        }

        current = head;
        long long int  gcd;
        long long int lcm;
        long long int a; long long int  b;
        int delete_count = 0;
        while (current->next){
            a = current->value;
            b = current->next->value;
            gcd = gcd_euclid(a, b);
            if (gcd != 1){
                lcm = (a*b)/gcd;
                current->value = lcm;
                current->next = current->next->next;
                if (current->next){
                    current->next->prev = current;
                }
                if (current->prev){
                    current = current->prev;
                }
                delete_count++;
            }
            else{
                current = current->next;
            }
        }

        current = head;
        vector<int> result(nums.size() - delete_count);
        for (int i = 0; i < result.size(); i++){
            result[i] = current->value;
            current = current->next;
        }
        return result;
    }
};