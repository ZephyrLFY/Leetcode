#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = l1;
        while (l1 || l2) {
            int left = l1 ? l1->val : 0;
            int right = l2 ? l2->val : 0;
            int sum = left + right + carry;
            carry = 0;
            if (sum >= 10) {
                carry = 1;
                sum = sum % 10;
            }
            l1->val = sum;
            if (l2) l2 = l2->next;
            if (l1->next) l1 = l1->next;
            else {
                if (!l2) break;
                l1->next = l2;
                l2 = nullptr;
                l1 = l1->next;
            }
        }
        if (carry) l1->next = new ListNode(1);
        return head;
    }
};