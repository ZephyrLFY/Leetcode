#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return false;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        bool dp[len][target + 1];
        dp[0][0] = true;
        if (nums[0] <= target) dp[0][nums[0]] = true;
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < target + 1; j++) {
                if (j == 0) {
                    dp[i][j] = true;
                    continue;
                }
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
            }
            if (dp[i][target]) return true; //剪枝
        }
        return dp[len - 1][target];
    }
};