#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = m > 1 ? head : nullptr;
        for (int i = 0; i < m - 2; ++i) {
            pre = pre->next;
        }
        int nums = n - m + 1;
        ListNode* cur = pre ? pre->next : head;
        ListNode* end = cur;
        ListNode* last = nullptr;
        ListNode* temp;
        for (int i = 0; i < nums; ++i) {
            temp = cur->next;
            cur->next = last;
            last = cur;
            cur = temp;
        }
        end->next = temp;
        if (pre) {
            pre->next = last;
            return head;
        }
        return last;
    }
};