#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int temp : nums) {
            if (seen.find(temp) != seen.end()) return true;
            else seen.insert(temp);
        }
        return false;
    }
};