#include <vector>

#include <tuple>
#include <queue>

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

class Greater{
public:
    bool operator() (tuple<int, int> a, tuple<int, int> b){
        return get<0>(a) > get<0>(b);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        priority_queue<tuple<int, int>, vector<tuple<int, int>>, Greater> current_values;

        for (int i = 0; i < k; i++){
            if (lists[k]){
                current_values.push({lists[k]->val, k});
                lists[k] = lists[k]->next;
            }
        }

        ListNode* header = new ListNode();
        ListNode* current = header;
        
        tuple<int, int> currentSmallest;
        int currentVal; int currentIndex;
        while (!current_values.empty()){
            currentSmallest = current_values.top();
            current_values.pop();

            currentVal = get<0>(currentSmallest);
            currentIndex = get<0>(currentSmallest);

            current->next = new ListNode(currentVal);
            current = current->next;

            if (lists[currentIndex]){
                current_values.push({lists[currentIndex]->val, currentIndex});
                lists[currentIndex] = lists[currentIndex]->next;
            }
        }

        return header->next;
    }
};

