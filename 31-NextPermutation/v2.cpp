#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        int i = len - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            int j = len - 1;
            while (nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums, i + 1);
    }

    void reverse(vector<int>& nums, int start) {
        int end = nums.size() - 1;
        while(end - start > 0)
            swap(nums[start++], nums[end--]);
    }   
};