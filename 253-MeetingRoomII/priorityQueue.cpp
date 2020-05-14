#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> endTime;
        sort(intervals.begin(), intervals.end());
        int res = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (endTime.empty() || intervals[i][0] < endTime.top())
                ++res;
            else
                endTime.pop();
            endTime.push(intervals[i][1]);
        }
        return res;
    }
};