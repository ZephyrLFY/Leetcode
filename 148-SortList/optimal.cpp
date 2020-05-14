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
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        
        
        return merge(sortList(head), sortList(slow));
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2) { //No extra space
        if (!head1) return head2;
        if (!head2) return head1;
        if (head1->val > head2->val)
            swap(head1, head2);
        ListNode* head = head1;
        ListNode* pre = nullptr;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                pre = head1;
                head1 = head1->next;
            }
            else {
                pre->next = head2;
                head2 = head2->next;
                pre = pre->next;
                pre->next = head1;
            }
        }
        if (head2) pre->next = head2;
        return head;
    }
};