#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        int dp[len][3];
        //dp[i][0]表示当天未持股，而且当天没有卖出
        dp[0][0] = 0;
        //dp[i][1]表示当天持股，可能是买入也可能是前几天买入
        dp[0][1] = 0 - prices[0];
        //dp[i][2]表示当天卖出，后一天就不可买入
        dp[0][2] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
            dp[i][2] = dp[i - 1][1] + prices[i];
        }
        return max(dp[len - 1][0], dp[len - 1][2]);
    }
};