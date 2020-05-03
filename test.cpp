#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int value;
    Node* pre;
    Node* next;
    Node(int x, int y) : key(x), value(y) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        setPre(key);
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->value = value;
            setPre(key);
            return;
        }
        if (capacity > 0) {
            capacity--;
        }
        else {
            int temp = tail->key;
            cache.erase(temp);
            if (tail->pre) {
                Node* cur = tail->pre;
                delete tail;
                tail = cur;
            }
            else delete tail;
        }
        head->next = new Node(key, value);
        queue.push_front(key);
        cache[key]->value = value;
    }

    void setPre(int key) {
        
    }
};