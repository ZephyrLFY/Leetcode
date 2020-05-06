#include "../cppLib.h"

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int l = 0, r = points.size() - 1;
        while (true) {
            int p = partition(points, l, r);
            if (p == K - 1) break;
            if (p < K - 1) l = p + 1;
            else r = p - 1;
        }
        return vector<vector<int>> (points.begin(), points.begin() + K);
    }

    bool isFar(vector<int>& p1, vector<int>& p2) {
        return pow(p1[0], 2) + pow(p1[1], 2) > pow(p2[0], 2) + pow(p2[1], 2);
    }

    bool isClo(vector<int>& p1, vector<int>& p2) {
        return pow(p1[0], 2) + pow(p1[1], 2) < pow(p2[0], 2) + pow(p2[1], 2);
    }

    int partition(vector<vector<int>>& points, int l, int r) {
        int pivot = l, left = l + 1, right = r;
        while (left <= right) {
            if (isFar(points[left], points[pivot]) && isClo(points[right], points[pivot]))
                swap(points[left++], points[right--]);
            if (!isFar(points[left], points[pivot])) left++; //注意是!isFar rather than isClo
            if (!isClo(points[right], points[pivot])) right--;
        }
        swap(points[pivot], points[right]);
        return right;
    }
};