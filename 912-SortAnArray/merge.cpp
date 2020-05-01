#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int left, int right) {  // 需要左右边界确定排序范围
        if (left >= right) return;
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);                           // 先对左右子数组进行排序
        mergeSort(nums, mid + 1, right);

        vector<int> temp(right - left + 1);                   // 临时数组存放合并结果
        int i = left, j = mid + 1;
        int cur = 0;
        while (i <= mid && j <= right) {                            // 开始合并数组
            if (nums[i] <= nums[j]) temp[cur] = nums[i++];
            else temp[cur] = nums[j++];
            cur++;
        }
        while (i <= mid) temp[cur++] = nums[i++];
        while (j <= right) temp[cur++] = nums[j++];

        for (int k = 0; k < temp.size(); k++) {             // 合并数组完成，拷贝到原来的数组中
            nums[left + k] = temp[k];
        }
    }
};