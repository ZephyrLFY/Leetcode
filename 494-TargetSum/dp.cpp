#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        /* 可转换为0-1背包问题
         * 设P为该数列中加+号的数列，N为加-号的数列, Q为全部数列
         * 有Sum(P) - Sum(N) = Target, 两边都加Sum(P) + Sum(N), 可得2 * Sum(P) = T + Sum(Q)
         * 所以转化为Q中挑出子序列P，和为Target + sum的二分之一即可
         * */
        long sum = 0;
        for (auto temp : nums) sum += temp;
        if ((sum + S) % 2 == 1 || S > sum) return 0;
        S = (S + sum) / 2;

        vector<int> dp(S + 1);
        dp[0] = 1;

        for (auto temp : nums) {
            for (int j = S; j >= temp; j--) //同理，状态压缩过的dp数组，从后往前填写，防止本轮的结果影响
                dp[j] += dp[j - temp];
        }
        return dp[S];
    }
};