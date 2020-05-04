#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> res;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 用r1, r2, c1, c2卡住四个角
        int len = matrix.size();
        if (len == 0) return res;
        int r1 = 0, r2 = len - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;
        while (r1 <= r2 && c1 <= c2) {
            for (int c = c1; c <= c2; c++) res.push_back(matrix[r1][c]);
            for (int r = r1 + 1; r <= r2; r++) res.push_back(matrix[r][c2]);
            if (r1 < r2 && c1 < c2) {
                for (int c = c2 - 1; c > c1; c--) res.push_back(matrix[r2][c]);
                for (int r = r2; r > r1; r--) res.push_back(matrix[r][c1]);
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return res;
    }
};