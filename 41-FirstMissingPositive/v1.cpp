#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {    
                swap(nums[nums[i] - 1], nums[i]);
                for(auto it = nums.begin(); it != nums.end(); it++)
                    cout << *it << " ";
                cout << i << endl;
            }
        }        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {3,0,2,4};
    cout << solu.firstMissingPositive(nums) << endl;
    return 0;
}