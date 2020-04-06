#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currSum = nums[0], maxSum = nums[0];

        for(int i = 1; i < n; i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {6,7,-15,7,16};
    cout << solu.maxSubArray(nums) << endl;
    return 0;
}