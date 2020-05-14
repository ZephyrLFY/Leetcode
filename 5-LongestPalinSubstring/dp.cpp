#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int start = 0;
        int res = 1;
        vector<vector<int>> dp(len, vector<int>(len));
        for (int i = len - 1; i >= 0; --i) {
            for (int j = len - 1; j >= i; --j) {
                if (i == j) dp[i][j] = 1;
                else if (s[i] == s[j]) {
                    if (i == j - 1) dp[i][j] = 2;
                    else if (dp[i + 1][j - 1]) dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                
                if (dp[i][j] > res) {
                    res = dp[i][j];
                    start = i;
                }
            }
        }
        return s.substr(start, res);
    }
};