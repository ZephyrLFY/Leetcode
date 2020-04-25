#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return len - 1;
        int first = 0, second = INT_MIN;
        for (int i = 1; i < len; i++) {
            if (nums[i] > nums[first]) {
                second = nums[first];
                first = i;
            }
            else if (nums[i] > second) {
                second = nums[i];
            }
        }
        return nums[first] >= 2 * second ? first : -1;
    }
};