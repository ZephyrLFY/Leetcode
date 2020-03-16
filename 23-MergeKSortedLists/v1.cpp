#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0) return NULL;
        else if(len == 1) return lists[0];
        int n = len / 2;
        vector<ListNode*>::iterator it = lists.begin();
        for(int i = 0; i < n; i++) {
            it++;
            lists[i] = merge2Lists(lists[i], lists[i + 1]);
            lists.erase(it);
        }
        mergeKLists(lists);
        return lists[0];
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* temp;
        ListNode* head;
        if(l1 == NULL || l2 == NULL) { //至少有一方是空的
            if(l1 != NULL) return l1;
            else if(l2 != NULL) return l2;
            else return NULL;
        }
        if(l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        temp = head;
        while(l1 && l2) { //开始循环
            if(l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
  			//处理剩余的那一条链
        if(l1) temp->next = l1;
        else temp->next = l2;
        return head;
    }
};