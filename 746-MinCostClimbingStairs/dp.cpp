#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if (len <= 1) return 0;
        int dp1 = cost[0], dp2 = cost[1];
        for (int i = 2; i < len; i++) {
            int temp = min(dp1, dp2) + cost[i];
            dp1 = dp2;
            dp2 = temp;
        }
        return min(dp1,dp2);
    }
};