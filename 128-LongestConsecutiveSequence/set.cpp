#include "../cppLib.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sets;
        int res = 0;
        for (int num : nums) sets.insert(num);
        for (int num : sets) {
            //以某个没有比它小1的数开头，计算连续长度
            if (num != INT_MIN && sets.count(num - 1))
                continue;
            int count = 1;
            while (num != INT_MAX && sets.count(num + 1)) {
                ++count;
                ++num;
            }
            res = max(res, count);
        }
        return res;
    }
};