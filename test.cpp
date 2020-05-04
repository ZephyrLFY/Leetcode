#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> res;
        for (int temp : nums) {
            res.push(temp);
            if (res.size() > k) res.pop();
        }
        return res.top();
    }
};