#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = nums.size();
        if (!len) return 0;
        int res = 0, sum = 0;
        vector<int> dp(len + 1);
        for (int i = 0; i < len; ++i) {
            dp[i + 1] = dp[i] + nums[i];
        }
        for (int i = 0; i < len; ++i) {
            for (int j = len; j > i; --j) {
                if (j - i < res) break;
                if (dp[j] - dp[i] == k) res = max(res, j - i);
            }
        }
        return res;
    }
};