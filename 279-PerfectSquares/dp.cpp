#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 0; i < n + 1; i++) {
            dp[i] = i;
            for (int j = 1; i >= j * j; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};