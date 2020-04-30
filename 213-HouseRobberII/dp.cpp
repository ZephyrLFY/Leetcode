#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        return max(rob_198(vector<int>(nums.begin(), nums.end() - 1)), rob_198(vector<int>(nums.begin() + 1, nums.end())));
    }

    int rob_198(vector<int> nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        int dp0 = 0, dp1 = 0, temp;
        for (auto num : nums) {
            temp = dp1;
            dp1 = max(dp1, dp0 + num);
            dp0 = temp;
        }
        return dp1;
    }
};