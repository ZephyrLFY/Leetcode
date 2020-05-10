#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        s = " " + s;
        int len = s.size();
        vector<int> dp(len);
        int res = 0;
        //dp[i] : ans of string ends with s[i]
        for (int i = 1; i < len; ++i) {
            char cur = s[i];
            if (cur == ')') {
                if (s[i - 1] == '(') dp[i] = dp[i - 2] + 2;
                else if (s[i - 1 - dp[i - 1]] == '(') dp[i] = dp[i - 1] + 2 + dp[i - 1 - dp[i - 1] - 1];
                res = max(res, dp[i]);
            }
            else dp[i] = 0;
        }
        return res;
    }
};