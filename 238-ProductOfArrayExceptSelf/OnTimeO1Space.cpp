#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        
        int pre = 1, behind = 1;
        int i = 1, j = len - 2;
        while (i < len) {
            pre *= nums[i - 1];
            behind *= nums[j + 1];
            res[i++] *= pre;
            res[j--] *= behind;
        }

        return res;
    }
};