#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //转化为背包问题，2S(P) - S(Q) = target, 要使target尽可能小，即S(Q) == 2 * S(P)
        int sum = 0;
        for (int temp : stones) sum += temp;
        int len = sum / 2 + 1; //容量，S(Q) / 2
        vector<int> dp(len, 0);
        for (int i = 0; i < stones.size(); i++)
            for (int j = len - 1; j >= stones[i]; j--)
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        return sum - 2 * dp[len - 1];
    }
};