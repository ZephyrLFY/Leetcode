#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        int i = len - 2;
        for(; i >= 0 && nums[i] >= nums[i + 1]; i--) ;
        if(i >= 0) {
            int j = len - 1;
            for(; nums[j] <= nums[i]; j--) ;
            swap(nums[i], nums[j]);
        }
        reverse(nums, i + 1);
    }

    void reverse(vector<int>& nums, int start) {
        int end = nums.size() - 1;
        while(end - start > 0)
            swap(nums[start++], nums[end--]);
    }   
};

int main()
{
    Solution solu;
    vector<int> nums = {1,1};
    solu.nextPermutation(nums);
    for(auto it = nums.begin(); it != nums.end(); it++)
        cout << *it << " ";
    return 0;
}