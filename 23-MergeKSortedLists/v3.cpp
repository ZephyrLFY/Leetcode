#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
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
        int interval = 1;
        while(interval < len) {
            for(int i = 0; i < len - interval; i += (interval * 2))
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            interval = interval * 2;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* head = temp;
        while(l1 && l2) {
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
        if(l1) temp->next = l1;
        else temp->next = l2;
        return head->next;
    }
};

int main()
{
    Solution solu;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(2);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(1);
    l2->next->next = new ListNode(2);
    vector<ListNode*> input = {l1, l2};
    ListNode* result = solu.mergeKLists(input);
    while(result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}