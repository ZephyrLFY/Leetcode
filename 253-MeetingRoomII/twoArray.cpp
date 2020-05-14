#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int len = intervals.size();
        vector<int> start(len);
        vector<int> end(len);
        for (int i = 0; i < len; ++i) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        int res = 0;
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        for (int i = 0, j = 0; i < len; ++i) {
            if (start[i] < end[j]) ++res;
            else ++j;
        }
        return res;
    }
};