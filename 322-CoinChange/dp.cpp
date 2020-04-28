#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<long> dp(amount + 1);
        dp[0] = 0;
        for (int coin : coins) {
            if (coin <= amount) dp[coin] = 1;
        }
        for (int i = 1; i < amount + 1; i++) {
            dp[i] = INT_MAX;
            for (int temp : coins)
                if (i >= temp) dp[i] = min(dp[i], dp[i - temp] + 1);
        }
        return dp[amount] >= INT_MAX ? -1 : dp[amount];
    }
};