#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        
        int diff = 0, dp = 0, res = 0;

        for (int i = 1; i < len; i++) {
            diff = prices[i] - prices[i - 1];
            dp = max(0, dp + diff);
            res = max(res, dp);
        }
        return res;
    }
};