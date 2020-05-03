#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        int len = nums.size() - 1;
        res[0] = searchLower(nums, target, 0, len);
        if (res[0] == -1) res[1] = -1;
        else res[1] = searchUpper(nums, target, res[0], len);
        return res;
    }
    
    int searchLower(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target){
            if (mid == 0 || nums[mid - 1] != target) return mid;
        }
        if (nums[mid] < target) return searchLower(nums, target, mid + 1, right);
        return searchLower(nums, target, left, mid - 1);
    }
    
    int searchUpper(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target){
            if (mid == nums.size() - 1 || nums[mid + 1] != target) return mid;
        }
        if (nums[mid] > target) return searchUpper(nums, target, left, mid - 1);
        return searchUpper(nums, target, mid + 1, right);
    }
};