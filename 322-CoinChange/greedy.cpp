#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int res = INT_MAX;
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.rbegin(),coins.rend());
        helper(coins, amount, 0, 0);
        return res == INT_MAX ? -1 : res;
    }

    void helper(vector<int>& coins, int amount, int index, int count) {
        if (amount == 0) {
            res = min(count, res);
            return;
        }
        if (index == coins.size()) return;

        for (int k = amount / coins[index]; k >= 0 && k + count < res; k--) {
            //k代表当前硬币选几个，最少选0个
            helper(coins, amount - k * coins[index], index + 1, count + k);
        }
    }
};