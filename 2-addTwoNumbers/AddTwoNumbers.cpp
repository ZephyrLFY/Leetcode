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
        bool carry = false;                             //进位标识
        int value = 0;

        //先遍历直到两条链都没到空的地方
        while(l1 != NULL && l2 != NULL)
        {
            value = carry ? l1->val + l2->val + 1 : l1->val + l2->val;
            cout << l1->val << " " << l2->val << " " << value << endl;
            //对进位进行处理
            if(value >= 10)
            {
                value = value % 10;
                carry = true;
            }
            else
                carry = false;
            //创建新的节点
            ListNode* temp = new ListNode(value);
            l3->next = temp;
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        //如果两个数都空了
        if(l1 == NULL && l2 == NULL)
        {
            //看要不要进位
            if(carry)
            {
                ListNode* temp = new ListNode(1);
                l3->next = temp;
            }
        }
        else
        {   
            //防止代码冗余，将剩余的那个数表示为left
            ListNode* left = l1 ? l1 : l2;
            l3->next = left;
            //如果有进位要求
            while(carry)
            {
                left->val += 1;
                if(left->val == 10)
                {
                    left->val = 0;
                    cout << left->val << endl;
                    //判断剩余的那个链是否结束
                    if(left->next == NULL)
                    {
                        left->next = new ListNode(1);
                        carry = false;
                    }
                    else
                        left= left->next;
                }
                else
                    carry = false;
            }
        }
        
        l3 = start->next;
        return l3;
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

    ListNode* l1 = solution->createList("1");
    ListNode* l2 = solution->createList("99");
    solution->printList(solution->addTwoNumbers(l1,l2));

    return 0;
}
