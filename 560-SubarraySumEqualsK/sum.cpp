#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int res = 0;
        vector<int> sum (len + 1);
        sum[0] = 0;
        for (int i = 1; i <= len; i++) {
            //sum[i] -> sum of [0, i)
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int i = 0; i <= len; i++) {
            for (int j = i + 1; j <= len; j++) {
                int temp = sum[j] - sum[i];
                if (temp == k) res++;
            }
        }
        return res;
    }
};