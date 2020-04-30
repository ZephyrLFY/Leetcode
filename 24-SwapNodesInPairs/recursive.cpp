#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* temp = swapPairs(head->next->next);
        ListNode* res = head->next;
        res->next = head;
        head->next = temp;
        return res;
    }
};