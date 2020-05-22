#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        int lenA = A.size(), lenB = B.size();
        while (i < lenA && j < lenB) {
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            if (lo <= hi) {
                vector<int> temp = {lo, hi};
                res.push_back(temp);
            }
            if (A[i][1] < B[j][1]) ++i;
            else ++j;
        }
        return res;
    }
};