#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        unordered_map<int, ListNode*> chart;
        ListNode* it = head;
        int i = 1;
        bool flag = true;
        while(flag) {
            chart[i] = it;
            if(it->next == NULL) flag = false;
            else {
                it = it->next;
                i++;
            }
        }
        if(i == n) { //要删除的是第一个点
            if(i > 1) head = head->next; //后面还有点
            else head = NULL; //光杆司令
        }
        else {
            if(n == 1) chart[i - 1]->next = NULL; //要删的是倒数第一个点
            else chart[i - n]->next = chart[i - n + 2]; //正常情况
        }
        return head;
    }
};