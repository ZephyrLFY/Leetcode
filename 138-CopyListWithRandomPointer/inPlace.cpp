#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        //克隆源节点
        Node* p = head;
        while (p) {
            Node* temp = p->next;
            p->next = new Node(p->val);
            p->next->next = temp;
            p = temp;
        }
        //给克隆节点的 random 赋值
        p = head;
        while (p) {
            if (p->random) p->next->random = p->random->next;
            p = p->next->next;
        }
        //拆分
        p= head;
        Node* cloneHead = p->next;
        Node* cloneP = cloneHead;
        while (cloneP->next) {
            //原链表
            p->next = p->next->next;
            p=p->next;
            //克隆链表
            cloneP->next = cloneP->next->next;
            cloneP = cloneP->next;
        }
        //最后不要忘了给原链表收尾
        p->next = nullptr;
        return cloneHead;
    }
};