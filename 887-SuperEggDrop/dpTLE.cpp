#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1));
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= K; j++)
                dp[i][j] = i;
        }

        for (int i = 0; i <= K; i++) {
            dp[0][i] = 0;
        }
        dp[1][0] = 0;
        for (int i = 1; i <= K; i++) {
            dp[1][i] = 1;
        }
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 0;
            dp[i][1] = i;
        }

        for (int i = 2; i <= N; i++) {
            for (int j = 2; j <= K; j++) {
                for (int k = 1; k <= i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k - 1][j - 1], dp[i - k][j]) + 1);
                }
            }
        }
        return dp[N][K];
    }
};