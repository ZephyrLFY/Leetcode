#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (!rows) return 0;
        int cols = grid[0].size();
        int res = 0;
        int temp = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j]) {
                    dfs(grid, i, j, rows, cols, temp);
                    res = max(res, temp);
                    temp = 0;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int rows, int cols, int& res) {
        ++res;
        grid[row][col] = 0;
        if (row > 0 && grid[row - 1][col]) dfs(grid, row - 1, col, rows , cols, res);
        if (row < rows - 1 && grid[row + 1][col]) dfs(grid, row + 1, col, rows, cols, res);
        if (col > 0 && grid[row][col - 1]) dfs(grid, row, col - 1, rows, cols, res);
        if (col < cols - 1 && grid[row][col + 1]) dfs(grid, row, col + 1, rows, cols, res);
    }
};