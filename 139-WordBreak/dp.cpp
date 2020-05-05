#include "../cppLib.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len + 1);
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            for (string temp : wordDict) {
                int wordLen = temp.size();
                if (i >= wordLen && s.substr(i - wordLen, wordLen) == temp)
                    dp[i] = dp[i] || dp[i - wordLen];
            }
        }
        return dp[len];
    }
};