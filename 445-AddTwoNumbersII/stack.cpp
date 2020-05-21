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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1;
        vector<int> num2;
        while (l1) {
            num1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            num2.push_back(l2->val);
            l2 = l2->next;
        }
        ListNode* after = nullptr;
        int carry = 0;
        while (num1.size() || num2.size()) {
            int left;
            if (num1.size()) {
                left = num1.back();
                num1.pop_back();
            }
            else left = 0;
            int right;
            if (num2.size()) {
                right = num2.back();
                num2.pop_back();
            }
            else right = 0;
            int sum = left + right + carry;
            carry = 0;
            if (sum >= 10) {
                sum = sum % 10;
                carry = 1;
            }
            ListNode* temp = new ListNode(sum);
            temp->next = after;
            after = temp;
        }
        if (carry) {
            ListNode* temp = new ListNode(1);
            temp->next = after;
            after = temp;
        }
        return after;
    }
};