#include "../cppLib.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (len <= 1) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 1;
        while (j < len) {
            if (intervals[j][0] <= intervals[i][1]) {
                intervals[i][1] = max(intervals[j][1], intervals[i][1]);
            }
            else {
                res.push_back(intervals[i]);
                i = j;
            }
            ++j;
        }
        if (i < len) res.push_back(intervals[i]);
        return res;
    }
};