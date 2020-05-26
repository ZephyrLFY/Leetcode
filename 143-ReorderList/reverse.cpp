#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;

        //快慢指针分割中点
        ListNode* slow = head;
        ListNode* quick = head;
        while (quick && quick->next) {
            slow = slow->next;
            quick = quick->next->next;
        }
        quick = slow->next;
        slow->next = nullptr;
        slow = quick;

        //翻转右边的链表
        ListNode* pre = nullptr;
        while (slow) {
            quick = slow->next;
            slow->next = pre;
            pre = slow;
            slow = quick;
        }
        slow = pre;

        //穿插链表
        while (head && slow) {
            pre = head;
            quick = head->next;
            head->next = slow;
            head = quick;
            quick = slow->next;
            slow->next = head;
            slow = quick;            
        }
        if (slow) pre->next = slow;
    }
};