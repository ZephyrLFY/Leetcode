#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int len = arr.size();
        int res = 1;
        vector<int> temp(len, 1);
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] == arr[j] + difference) {
                    temp[i] = max(temp[i], temp[j] + 1);
                    res = max(res, temp[i]);
                }
            }
        }
        return res;
    }
};