#include<iostream>
#include<unordered_map>
using namespace std;

struct MyListNode {
    int key;
    int val;
    MyListNode* pre = nullptr;
    MyListNode* next = nullptr;
    MyListNode(int x, int y) : key(x), val(y) {}
};

class DoubleList {
private:
    MyListNode* head;
    MyListNode* tail;
    int size;
public:
    DoubleList() {
        head = new MyListNode(0, 0);
        tail = new MyListNode(0, 0);
        head->next = tail;
        tail->pre = head;
        size = 0;
    }

    void addFirst(MyListNode* temp) {
        temp->next = head->next;
        head->next->pre = temp;
        head->next = temp;
        temp->pre = head;
        ++size;
    }

    void remove(MyListNode* temp) {
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        --size;
    }

    MyListNode* removeLast() {
        MyListNode* temp = tail->pre;
        if (temp == head) return nullptr;
        remove(temp);
        return temp;
    }

    int getSize() {
        return size;
    }
};

class LRUCache {
private:
    unordered_map<int, MyListNode*> map;
    int nums;
    DoubleList list;
public:
    LRUCache(int capacity) {
        nums = capacity;
    }
    
    int get(int key) {
        if (!map.count(key)) return -1;
        int res = map[key]->val;
        put(key, res);
        return res;
    }
    
    void put(int key, int value) {
        if (map.count(key)) list.remove(map[key]);
        else if (nums == list.getSize()) {
            MyListNode* temp = list.removeLast();
            map.erase(temp->key);
        }
        MyListNode* temp = new MyListNode(key, value);
        list.addFirst(temp);
        map[key] = temp;
    }
};