#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        
        vector<int> follow(len);
        follow[0] = 1;
        res[0] = 1;
        for (int i = 1; i < len; i++) {
            follow[i] = follow[i - 1] * nums[i - 1];
            res[i] = follow[i];
        }

        follow[len - 1] = 1;
        for (int i = len - 2; i >= 0; i--) {
            follow[i] = follow[i + 1] * nums[i + 1];
            res[i] *= follow[i];
        }
        return res;
    }
};