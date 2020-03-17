#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int flag = -1;
        int len = nums.size();
        if(len <= 1) return;
        for(int i = 0; i < len; i++)
            if(nums[i] < nums[i + 1]) flag = i;
        if(flag != -1)
            swap(nums[flag], nums[flag + 1]);
        else 
            reverse(nums.begin(), nums.end());
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {1,1,5};
    solu.nextPermutation(nums);
    for(auto it = nums.begin(); it != nums.end(); it++)
        cout << *it << " ";
    return 0;
}