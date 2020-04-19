#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    vector<int> index; //索引数组，记录原数组各元素的索引位置。改变该数组，就可以通过此数组访问到原数组中元素的不同排序
    vector<int> temp; //暂存当前索引数组，以便在本次中排序时使用
    vector<int> counter; //计数数组，即最后答案

public:
    vector<int> countSmaller(vector<int>& nums) {
        //Corner Case
        int len = nums.size();
        if (len == 0) return {};
        if (len == 1) return {0};

        index.resize(len);
        temp.resize(len);
        counter.resize(len);

        for (int i = 0; i < len; i++) index[i] = i; //For the first time, initiate index array manually.

        mergeSort(nums, 0, len - 1);
        return counter;
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left == right) return; //There is only one element in [left,right]
        int mid = left + (right - left) / 2; //Divide to 2 parts
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        //If nums[index[mid] <= nums[index[mid + 1]]], this subarray [left, right] is already sorted
        if (nums[index[mid]] > nums[index[mid + 1]])
            mergeCount(nums, left, mid, right);
    }

    void mergeCount(vector<int>& nums, int left, int mid, int right) {
        //Save last index array for this turn
        for (int i = left; i <= right; i++) temp[i] = index[i];
        
        int i = left, j = mid + 1;
        for (int k = left; k <= right; k++) {
            //No integer left in [left,mid]
            if (i > mid) index[k] = temp[j++];
            else if (j > right) {
                //No integer left in [mid + 1, right], we should count how many nums smaller than nums[temp[i]]
                index[k] = temp[i++];
                counter[index[k]] += (right - mid);
            }
            else if (nums[temp[i]] <= nums[temp[j]]) {
                index[k] = temp[i++];
                counter[index[k]] += (j - mid - 1);
            }
            else index[k] = temp[j++];
        }
    }
    /* 这个算法的精妙之处有两个
     * 一是使用了索引数组，这样就可以在不动原数组的情况下去进行归并排序。因为最后要以原数组的顺序输出答案
     * 二是在每一次归并排序的时候，左数组和右数组都有自己的counter，来记录每个数右边比他小的数
     *  所以在把两部分合起来的时候，对于左边的数，需要考虑的只有右边数组中有几个比它先进的，加到已有的结果上即可
     *  而对于右边，不需要考虑左边数组，因为本来左边数组在原数组的位置就都在他前面
     * */
};