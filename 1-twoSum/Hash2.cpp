#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ans;
        vector<int> res(2);
        for (int i = 0; i < nums.size(); i++) {
            if (ans.find(target - nums[i]) != ans.end()) {
                res[1] = i;
                res[0] = ans[target - nums[i]];
            }
            else {
                ans[nums[i]] = i;
            }
        }
        return res;
    }
};