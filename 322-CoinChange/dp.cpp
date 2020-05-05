#include <iostream>
#include <vector>
using namespace std;

/* 二维dp数组
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        if (!len || !amount) return 0;
        vector<vector<long>> dp(len, vector<long>(amount + 1, INT_MAX)); //dp[i][j] : 用前i种硬币凑出面额j
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < amount + 1; j++) {
                if (!j) dp[i][j] = 0;
                else {
                    if (i != 0) dp[i][j] = dp[i - 1][j];
                    if (j >= coins[i]) {
                        dp[i][j] = min(dp[i][j], dp[i][j - coins[i]] + 1);
                    }
                }
            }
        }
        int res = dp[len - 1][amount];
        return res == INT_MAX ? -1 : res;
    }
};
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!coins.size() || !amount) return 0;
        vector<long> dp(amount + 1); //压缩成一维, dp[i] : 凑出面额i的答案
        for (int i = 1; i < amount + 1; i++) {
            dp[i] = INT_MAX;
            for (int temp : coins)
                if (i >= temp) dp[i] = min(dp[i], dp[i - temp] + 1);
        }
        int res = dp[amount];
        return res == INT_MAX ? -1 : res;
    }
};