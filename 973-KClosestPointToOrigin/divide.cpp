#include "../cppLib.h"

class Solution {
private:
    priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> queue;
    vector<vector<int>> res;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        for (int i = 0; i < points.size(); i++) {
            int temp = pow(points[i][0], 2) + pow(points[i][1], 2);
            queue.push(vector<int>{temp,i});
        }
        helper(points, K);
        return res;
    }

    void helper(vector<vector<int>>& points, int K) {
        if (K == 0 || queue.empty()) return;
        auto cur = queue.top();
        queue.pop();
        res.push_back(points[cur[1]]);
        helper(points, K - 1);
    }
};