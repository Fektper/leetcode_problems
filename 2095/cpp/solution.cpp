
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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* cur = head;
        while (cur != nullptr){
            cur = cur->next;
            n++;
        }

        if (n == 1){
            return nullptr;
        }
        if (n == 2){
            head->next = nullptr;
            return head;
        }

        int t = n/2;
        int i = 1;
        cur = head;
        while (i < t){
            i++;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};