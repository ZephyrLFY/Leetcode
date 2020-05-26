#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        int i = 1;
        vector<int> dp(len);
        dp[0] = 1;
        while (i < len) {
            if (ratings[i] > ratings[i - 1]) dp[i] = dp[i - 1] + 1;
            else if (ratings[i] == ratings[i - 1]) dp[i] = 1;
            else {
                dp[i] = 1;
                int j = i - 1;
                while (j >= 0 && ratings[j + 1] < ratings[j] && dp[j + 1] == dp[j]) {
                    ++dp[j--];
                }
            }
            ++i;
        }
        int res = 0;
        for (auto num : dp)
            res += num;
        return res;
    }
};