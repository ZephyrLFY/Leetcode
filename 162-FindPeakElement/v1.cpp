#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        int right = nums.size() - 2;
        int left = 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid - 1]) right = mid - 1;
            else if (nums[mid] < nums[mid + 1]) left = mid + 1;
            else return mid - 1;
        }
        return -1;
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {1,2,3,4,7};
    cout << solu.findPeakElement(nums) << endl;
}