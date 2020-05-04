#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (map.count(sum - k)) res += map[sum - k];
            map[sum] = (map.count(sum) ? map[sum] : 0) + 1;
        }
        
        return res;
    }
};