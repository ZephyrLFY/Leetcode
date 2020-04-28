#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        int dp0 = nums[0];
        int dp1 = max(dp0, nums[1]);
        for (int i = 2; i < len; i++) {
            int temp = max(dp1, dp0 + nums[i]);
            dp0 = dp1;
            dp1 = temp;
        }
        return dp1;
    }
};