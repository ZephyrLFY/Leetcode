#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return 0;
        vector<int> dp(len);
        dp[len - 1] = 0; //给最后一个元素的dp赋值0
        for(int i = len - 2; i >= 0; i--) {
            if(nums[i] == 0) dp[i] = INT_MAX; //若某元素为0，那么从这一点永远不可能到达尾端
            else if(i + nums[i] >= len - 1) dp[i] = 1; //能一步跳到结尾的情况
            else {
                int step = len;
                for(int j = 1; j <= nums[i]; j++) step = min(step, dp[i + j]);
                dp[i] = step + 1; //比较所能跳到的位置里面，到结尾最近的
            }
        }
        return dp[0];
    }
};