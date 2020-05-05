#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int> endTime;
        sort(intervals.begin(), intervals.end());
        for (auto cur : intervals) {
            if (!endTime.empty() && cur[0] <= endTime.top())
                endTime.pop();
            endTime.push(cur[1]);
        }
        return endTime.size();
    }
};