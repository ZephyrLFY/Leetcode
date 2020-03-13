#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int> >result(0);
        int rNum = -1;
        for(int i = 0; i < len - 2; i++) {
            int j = i + 1;
            int k = len - 1;
            if(nums[i] > 0) break;
            else if(i > 0 && nums[i] == nums[i - 1]) continue;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    rNum++;
                    result.resize(rNum + 1);
                    result[rNum] = {nums[i], nums[j],nums[k]};
                    while(j < k && nums[j] == nums[++j]);
                    while(j < k && nums[k] == nums[--k]);
                }
                else if(sum < 0) j++;
                else k--;
            }
        }
        return result;
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    solu.threeSum(nums);
}