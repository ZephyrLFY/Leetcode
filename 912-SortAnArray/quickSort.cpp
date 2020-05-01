#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void q_sort(vector<int> &nums, int l, int r){
        if(l >= r) return;
        int i = l, j = r, x = nums[(l + r) >> 1];
        while(i <= j) {
            while(nums[i] < x) i++;
            while(nums[j] > x) j--;
            if(i <= j) swap(nums[i++], nums[j--]);
        }
        q_sort(nums, l, j);
        q_sort(nums, i, r);
    }


    vector<int> sortArray(vector<int>& nums) {
        q_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

class Solution2 {
public:
    int partition(vector<int>& nums,int left,int right) {
        int tmp = nums[left];
        while(left < right) {
            while(left < right && nums[right] >= tmp) {
                right--;
            }
            nums[left] = nums[right];
            while(left < right && nums[left] <= tmp) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = tmp;
        return left;
    }
    
    void quickSort(vector<int>& nums,int left,int right) {
        if(left >= right) {
            return;
        }
        int div = partition(nums, left, right);
        quickSort(nums, left, div - 1);
        quickSort(nums, div + 1, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};