#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        int i = 0, j = 0, k = 0;
        sort(nums.begin(), nums.end());
        for (k = 0; k < len - 2; k++) {
            i = k + 1;
            j = len - 1;
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> temp = {nums[k], nums[i], nums[j]};
                    res.push_back(temp);
                    while (i < j && nums[i] == nums[++i]);
                    while (j > i && nums[j] == nums[--j]);
                }
                else if (sum < 0) while (i < j && nums[i] == nums[++i]);
                else while (j > i && nums[j] == nums[--j]);
            }
        }
        return res;
    }
};