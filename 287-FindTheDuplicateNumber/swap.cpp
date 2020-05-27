#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            while (nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
            if (nums[i] != i + 1) return nums[i];
        }
        return -1;
    }
};