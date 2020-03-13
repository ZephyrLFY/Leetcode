#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result(0);
        int rNum = -1;
        int len = nums.size();
        unordered_map<int, int> temp;
        for(int i = 0; i < len - 2; i++) {
            for(int j = i + 1; j < len; j++) {
                unordered_map<int, int>::const_iterator got = temp.find(0 - nums[i] - nums[j]);
                if(got != temp.end() && got->second > i && got->second != j) {
                    rNum++;
                    result.resize(rNum + 1);
                    result[rNum].resize(3);
                    result[rNum][0] = nums[i];
                    result[rNum][1] = nums[j];
                    result[rNum][2] = nums[got->second];
                    cout << nums[i] << " " << nums[j] << " " << nums[got->second] << endl;
                }
                temp[nums[j]] = j;
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