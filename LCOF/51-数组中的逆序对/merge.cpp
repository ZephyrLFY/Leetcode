#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int right = nums.size() - 1;
        int left = 0;
        vector<int> temp(right + 1, 0);
        return mergeSort(nums, temp, left, right);
    }

    int mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int tempNum = mergeSort(nums, temp, left, mid) + mergeSort(nums, temp, mid + 1, right);
        int len = right - left + 1;
        for (int i = left; i <= right; ++i) {
            temp[i] = nums[i];
        }
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (temp[i] <= temp[j]) {
                tempNum += j - mid - 1;
                nums[left++] = temp[i++];
            }
            else {
                nums[left++] = temp[j++];
            }
        }
        while (i <= mid) {
            tempNum += j - mid - 1;
            nums[left++] = temp[i++];
        }
        while (j <= right) nums[left++] = temp[j++];
        return tempNum;
    }
};