#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        helper(nums, k, 0, len, len);
    }

    void helper(vector<int>& nums, int k, int start, int len, int end) {
        k = k % len;
        if (k == 0) return;
        for (int i = 0; i < k; i++)
            swap(nums[start + i], nums[end - k + i]);
        helper(nums, k, start + k, len - k, end);
    }
};