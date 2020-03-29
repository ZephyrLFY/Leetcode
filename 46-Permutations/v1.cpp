#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        addPath(nums);
        return result;
    }

    void addPath(vector<int>& nums) {
        int len = nums.size();
        if(path.size() == len) {
            result.push_back(path);
            return;
        }
        for(int i = 0; i < len; i++) {
            if(find(path.begin(), path.end(), nums[i]) != path.end()) continue;
            path.push_back(nums[i]);
            addPath(nums);
            path.pop_back();
        }
    }

private:
    vector<vector<int> > result;
    vector<int> path;
};