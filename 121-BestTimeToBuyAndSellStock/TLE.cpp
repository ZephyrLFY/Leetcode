#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        int res = 0;
        for (int start = 0; start < len; start++) {
            for (int end = start + 1; end < len; end++) {
                res = max(res, prices[end] - prices[start]);
            }
        }
        return res;
    }
};