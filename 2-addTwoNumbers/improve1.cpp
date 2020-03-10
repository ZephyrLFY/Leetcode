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

        ListNode* start = new ListNode(0);              //起始点
        ListNode* l3 = start;                           //操作指针
        int carry = 0;                             //进位标识
        int value = 0;
        int val1 = 0;
        int val2 = 0;

        //先遍历直到两条链都没到空的地方
        while(l1 || l2)
        {
            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;
            value = val1 + val2 + carry;

            //对进位进行处理
            if(value >= 10)
            {
                value = value % 10;
                carry = 1;
            }
            else
                carry = 0;
            //创建新的节点
            ListNode* temp = new ListNode(value);
            l3->next = temp;
            l3 = l3->next;
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
        }
        if(carry)
        {
            l3->next = new ListNode(1);
        }
        
        return start->next;
    }

    ListNode* createList(string number) {
        ListNode* start = new ListNode(number.at(0) - 48);
        ListNode* l1 = start;
        number.erase(0,1);
        while(!number.empty())
        {
            l1->next = new ListNode(number.at(0) - 48);
            l1 = l1->next;
			number.erase(0,1);
        }
        return start;
    }

    void printList(ListNode* l1) {
        string result = "";
        while(l1->next != NULL)
        {
            result.append(to_string(l1->val) + "->");
            l1 = l1->next;
        }
        result.append(to_string(l1->val));
        cout << "The result is : " << result << endl;
    }
};

int main()
{
    Solution* solution = new Solution;

    ListNode* l1 = solution->createList("12");
    ListNode* l2 = solution->createList("1234");
    solution->printList(solution->addTwoNumbers(l1,l2));

    return 0;
}
