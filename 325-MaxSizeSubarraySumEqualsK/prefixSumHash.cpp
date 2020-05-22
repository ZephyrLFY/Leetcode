#include "../cppLib.h"

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        int len = nums.size();
        unordered_map<int, int> map;
        map[0] = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            if (!map.count(sum)) map[sum] = i + 1;
            if (map.count(sum - k)) res = max(res, i + 1 - map[sum - k]);
        }
        return res;
    }
};