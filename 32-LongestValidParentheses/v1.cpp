#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int len = s.size();
        if(len <= 1) return 0; //特判
        int dp[len];
        memset(dp, 0, len*sizeof(int));
        for(int i = 1; i < len; i++) {
            if(s[i] == ')') {
                if(s[i - 1] == '(') dp[i] = (i > 1 ? dp[i - 2] : 0) + 2;
                else if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] > 1 ? dp[i - dp[i - 1] - 2] : 0);
                maxLen = max(maxLen, dp[i]);
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution solu;
    string s;
    solu.longestValidParentheses(s);
}