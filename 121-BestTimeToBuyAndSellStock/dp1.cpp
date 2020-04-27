#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        vector<int> diff(len - 1);
        for (int i = 0; i < len - 1; i++) {
            diff[i] = prices[i + 1] - prices[i];
        }

        vector<int> dp(diff.size());
        dp[0] = max(0, diff[0]);
        int res = dp[0];
        for (int i = 1; i < diff.size(); i++) {
            dp[i] = max(0, dp[i - 1] + diff[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};