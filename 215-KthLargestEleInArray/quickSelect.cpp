#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        quickSort(nums, 0, len - 1, len - k);
        return nums[len - k];
    }

    void quickSort(vector<int>& nums, int left, int right, int k) {
        if (left >= right) return;
        int mid = partition(nums, left, right);
        if (mid == k) return;
        quickSort(nums, left, mid - 1, k);
        quickSort(nums, mid + 1, right, k);
    }

    int partition(vector<int>& nums, int left, int right) {
        if (left >= right) return right;
        int mid = rand() % (right - left + 1) + left;
        swap(nums[left], nums[mid]);
        int temp = nums[left];
        int i = left + 1;
        while (i <= right) {
            if (nums[i] > temp && nums[right] < temp) {
                swap(nums[i++], nums[right--]);
            }
            else {
                if (nums[i] <= temp) ++i;
                if (nums[right] >= temp) --right;
            }
        }
        swap(nums[left], nums[right]);
        return right;
    }
};