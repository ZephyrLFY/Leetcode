#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return len;
        vector<int> tail; //tail[i] : 长度为i + 1的递增序列的最小结尾值
        tail.push_back(nums[0]);
        int end = 0;
        for (int i = 1; i < len; ++i) {
            if (nums[i] > tail[end]) {
                tail.push_back(nums[i]);
                ++end;
            }
            else {
                int left = 0;
                int right = end - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (tail[mid] < nums[i]) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                tail[left] = nums[i];
            }
        }
        return end + 1;
    }
};