#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int rows = A.size();
        if (!rows) return 0;
        int cols = A[0].size();
        int res = INT_MAX;
        vector<int> dp(cols);
        for (int i = 0; i < cols; ++i) dp[i] = A[0][i];
        for (int i = 1; i < rows; ++i) {
            vector<int> tmp(dp.begin(), dp.end());
            for (int j = 0; j < cols; ++j) {
                int temp = dp[j];
                if (j > 0) temp = min(temp, dp[j - 1]);
                if (j < cols - 1) temp = min(temp, dp[j + 1]);
                tmp[j] = temp + A[i][j];
            }
            for (int i = 0; i < cols; ++i) dp[i] = tmp[i];
        }
        for (int i = 0; i < cols; ++i) res = min(res, dp[i]);
        return res;
    }
};