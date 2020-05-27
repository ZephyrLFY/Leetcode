#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<bool> dp(len, false);
        dp[0] = true;
        for (int i = 0; i < len - 1; ++i) {
            if (dp[i]) {
                for (int j = 0; j <= nums[i] && i + j < len; ++j) {
                    dp[i + j] = true;
                }
            }
        }
        return dp[len - 1];
    }
};