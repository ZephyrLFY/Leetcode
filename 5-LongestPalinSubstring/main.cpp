#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len == 1) { 
            return s;
        }
        int dp[len][len];
        memset(dp, 0, sizeof(dp));
        int max = 1;
        int start = 0;
        for(int i = 0; i < len; i++) {
            dp[i][i] = 1;
            if(i < len-1 && s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                max = 2;
                start = i;
            }
        }
        for(int l = 3; l <= len; l++) {
            for(int i = 0; i + l -1 < len; i++) {
                int j = i + l - 1;
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = 1;
                    max = l;
                    start = i;
                }
            }
        }
        return s.substr(start, max);
    }
};

int main()
{
    string s = "sadsafasfadsadqwdasd";
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
}