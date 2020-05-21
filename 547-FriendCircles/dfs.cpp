#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int nums = M.size();
        int res = 0;
        vector<int> seen(nums);
        for (int i = 0; i < nums; ++i) {
            if (!seen[i]) {
                ++res;
                dfs(M, seen, i);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& M, vector<int>& seen, int i) {
        for (int j = 0; j < M[i].size(); ++j) {
            if (M[i][j] && seen[j] == 0) {
                seen[j] = 1;
                dfs(M, seen, j);
            }
        }
    }
};