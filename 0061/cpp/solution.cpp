#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr){
            return head;
        }
        int n = 0;
        ListNode* current = head;
        ListNode* last;
        while (current != nullptr){
            n++;
            last = current;
            current = current->next;
        }
        k = k % n;
        if (k == 0){
            return head;
        }
        
        current = head;
        ListNode* holder;
        for (int i = 0; i < n-k; i++){
            if (i == n-k-1){
                holder = current->next;
                current->next = nullptr;
                current = holder;
            }
            else {
                current = current->next;
            }
        }
        ListNode* new_first = current;
        last->next = head;

        return new_first;
    }
};