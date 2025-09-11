#include <vector>

using namespace std;

// 
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        int thisMinIndex;
        int thisMinValue;
        bool oneExists = true;
        ListNode* header = new ListNode();
        ListNode* current = header;
        while (oneExists){
            oneExists = false;
            thisMinValue = __INT32_MAX__;
            thisMinIndex = 0;

            for (int i = 0; i < k; i++){
                if (lists[i]){
                    oneExists = true;
                    if (lists[i]->val < thisMinValue){
                        thisMinValue = lists[i]->val;
                        thisMinIndex = i;
                    }
                }
            }

            if (oneExists){
                current->next = new ListNode(thisMinValue);
                current = current->next;
                lists[thisMinIndex] = lists[thisMinIndex]->next;
            }
        }

        return header->next;
    }
};