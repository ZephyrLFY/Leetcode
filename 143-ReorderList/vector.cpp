#include <iostream>
#include <vector>
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
        vector<ListNode*> nodes;
        ListNode* scan = head;
        while (scan) {
            nodes.push_back(scan);
            scan = scan->next;
        }
        int len = nodes.size();
        int i = 0, j = len - 1;
        while (i < j) {
            nodes[i++]->next = nodes[j];
            nodes[j--]->next = nodes[i];
        }
        nodes[i]->next = nullptr;
    }
};