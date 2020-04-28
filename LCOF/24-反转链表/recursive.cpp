#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head && head->next) {
            auto temp = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            head = temp;
        }
        return head;
    }
};