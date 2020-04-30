#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int res;
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        if (len == 0) return 0;
        dfs(nums, 0, S, 0, len);
        return res;
    }

    void dfs(vector<int>& nums, int curSum, int S, int index, int len) {
        if (index == len) {
            if (curSum == S) res++;
            return;
        }
        dfs(nums, curSum - nums[index], S, index + 1, len);
        dfs(nums, curSum + nums[index], S, index + 1, len);
    }
};