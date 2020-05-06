#include "../cppLib.h"

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<int, vector<int>, less<int>> stack;
        unordered_map<int, vector<vector<int>>> map;
        vector<vector<int>> res;
        int size = 0;
        for (int i = 0; i < points.size(); i++) {
            int temp = pow(points[i][0], 2) + pow(points[i][1], 2);
            if (map[temp].empty()) stack.push(temp);
            map[temp].push_back(points[i]);
            size++;
            if (size > K) {
                int target = stack.top();
                map[target].pop_back();
                size--;
                if (map[target].empty()) stack.pop();
            }
        }
        while (!stack.empty()) {
            int temp = stack.top();
            stack.pop();
            for (auto cur : map[temp]) {
                res.push_back(cur);
            }
        }
        return res;
    }
};