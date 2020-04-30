#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
public:
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for (int right = 0; right < len; right++) {
            for (int left = 0; left <= right; left++) {
                if (s[left] == s[right] && (right - left <= 2 || dp[left + 1][right - 1]))
                    dp[left][right] = true;
            }
        }
        backtracking(s, dp, 0, len);
        return res;
    }

    void backtracking(string s, vector<vector<bool>>& dp, int left, int right) {
        if (left == right) {
            res.push_back(path);
            return;
        }
        for (int i = left; i < right; i++) {
            if (!dp[left][i]) continue;
            path.push_back(s.substr(left, i + 1 - left));
            backtracking(s, dp, i + 1, right);
            path.pop_back();
        }
    }
};