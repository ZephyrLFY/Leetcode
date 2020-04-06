#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        return conquer(nums, 0, len - 1);
    }

    int conquer(vector<int>& nums, int left, int right) {
        // 分治算法，求左边的解，右边的解，和分割点延伸的解
        if(left == right) return nums[left];
        int div = left + (right - left) / 2;
        int leftSub = conquer(nums, left, div);
        int rightSub = conquer(nums, div + 1, right);
        int crossSub = crossSum(nums, left, right, div);
        return max(max(leftSub, rightSub), crossSub);
    }

    int crossSum(vector<int>&nums, int left, int right, int div) {
        int leftSum = INT_MIN, rightSum = INT_MIN;
        int curSum = 0;
        for(int i = div; i > left - 1; i--) {
            // 往左延伸求解
            curSum += nums[i];
            leftSum = max(leftSum, curSum);
        }
        curSum = 0;
        for(int i = div + 1; i < right + 1; i++) {
            // 往右延伸
            curSum += nums[i];
            rightSum = max(rightSum, curSum);
        }
        return leftSum + rightSum;
    }
};