#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        if (head == slow && !fast) head = head->next;
        else if (!slow->next->next) slow->next = nullptr;
        else {
            ListNode* temp = slow->next->next;
            slow->next = temp;
        }
        
        return head;
    }
};