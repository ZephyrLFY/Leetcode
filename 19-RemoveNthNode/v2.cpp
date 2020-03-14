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
        if(head->next == NULL) {
            head = NULL;
            return head;
        }
        ListNode* i1 = head;
        ListNode* i2 = head;
        bool flag = true;
        while(flag) {
            i1 = i1->next;
            if(--n < 0) i2 = i2->next;
            if(i1->next == NULL) flag = false;
        }
        if(i2 == head && n == 1) head = head->next;
        else if(i2->next->next == NULL) i2->next = NULL;
        else i2->next = i2->next->next;
        return head;
    }
};