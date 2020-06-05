#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int len = arr.size();
        int res = 1;
        unordered_map<int, int> map;
        for (int i = 0; i < len; ++i) {
            int temp = (map.count(arr[i] - difference) ? map[arr[i] - difference] : 0) + 1;
            map[arr[i]] = temp;
            res = max(res, temp);
        }
        return res;
    }
};