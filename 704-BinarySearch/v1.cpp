#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size() - 1;
        if (end == -1) return -1;

        int start = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
};