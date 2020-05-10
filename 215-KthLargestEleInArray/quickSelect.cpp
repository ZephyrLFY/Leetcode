#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int res = -1;
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        quickSort(nums, len - k, 0, len - 1);
        if (res == -1) res = nums[len - k];
        return res;
    }
    
    void quickSort(vector<int>& nums, int target, int left, int right) {
        if (left > right) return;
        int pivot = partition(nums, left, right);
        if (pivot == target) {
            res = nums[pivot];
            return;
        }
        quickSort(nums, target, left, pivot - 1);
        quickSort(nums, target, pivot + 1, right);
    }
    
    int partition(vector<int>& nums, int left, int right) {
        if (left >= right) return right;
        int mid = left + (right - left) / 2;
        int temp = nums[mid];
        swap(nums[left], nums[mid]);
        int i = left + 1;
        while (i <= right) {
            if (nums[i] > temp && nums[right] < temp)
                swap(nums[i++], nums[right--]);
            if (nums[i] <= temp) ++i;
            if (nums[right] >= temp) --right;
        }
        swap(nums[left], nums[right]);
        return right;
    }
};