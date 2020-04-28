#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long l = nums[0], h = 0;
        for (auto temp : nums) {
            h += temp;
            l = temp > l ? temp : l;
        }
        //答案在maxnum与sum的范围内，所以先算出maxnum和sum，使用二分法

        while (l < h) {
            long mid = l + (h - l) / 2;
            long temp = 0;
            long cnt = 1;
            for (auto i : nums) { //进行分组，因为是连续的，所以可以这样分，每组的和都不大于设定的答案mid
                temp += i;
                if (temp > mid) {
                    temp = i;
                    cnt++;
                }
            }
            if (cnt > m) l = mid + 1;
            else h = mid;
        }
        return l;
    }
};