#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        if (!rows) return res;
        int cols = matrix[0].size();
        helper(matrix, res, 0, 0, cols - 1, rows - 1);
        return res;
    }

    void helper(vector<vector<int>>& matrix, vector<int>& res, int lc, int lr, int rc, int rr) {
        if (lc > rc || lr > rr) return;
        for (int i = lc; i <= rc; ++i) res.push_back(matrix[lr][i]);
        for (int i = lr + 1; i <= rr; ++i) res.push_back(matrix[i][rc]);
        if (lc < rc && lr < rr) {
            for (int i = rc - 1; i >= lc; --i) res.push_back(matrix[rr][i]);
            for (int i = rr - 1; i > lr; --i) res.push_back(matrix[i][lc]);
        }
        helper(matrix, res, lc + 1, lr + 1, rc - 1, rr - 1);
    }
};