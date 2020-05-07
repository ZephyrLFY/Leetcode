#include "../cppLib.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> store;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.count(val)) return false;
        store.push_back(val);
        map[val] = store.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) { //switch to back, or the index will be invalid because of erase
        if (map.count(val)) {
            int temp = store.back();
            map[temp] = map[val];
            store[map[val]] = temp;

            store.pop_back();
            map.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % store.size();
        return store[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */