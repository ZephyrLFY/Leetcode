#include <iostream>
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if (len < 3) return 0;
        vector<int> dp(len);
        for (int i = 0; i < 2 && i < len - 1; ++i) {
            dp[i] = cost[i];   
        }
        for (int i = 2; i < len; ++i) {
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
        }
        return min(dp[len - 1], dp[len - 2]);
    }
};

