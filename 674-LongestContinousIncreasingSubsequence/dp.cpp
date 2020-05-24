#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        if (!len) return 0;
        int res = 1, dp = 1;
        for (int i = 1; i < len; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++dp;
                res = max(res, dp);
            }
            else dp = 1;
        }
        return res;
    }
};