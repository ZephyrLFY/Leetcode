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
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        if (nums[0] <= target) dp[nums[0]] = true;
        for (int i = 1; i < len; i++) {
            for (int j = target; j >= nums[i]; j--) { //从后往前做，防止在更新后面的数组时用到本轮已更新的数据
                if (dp[target]) return true; //剪枝
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};