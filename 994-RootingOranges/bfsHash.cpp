#include "../cppLib.h"
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (!rows) return -1;
        int cols = grid[0].size();
        unordered_map<int, unordered_set<int>> check;
        queue<vector<int>> stack;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) check[i].insert(j);
                else if (grid[i][j] == 2) stack.push(vector<int>{i, j});
            }
        }
        if (check.empty()) return 0;
        int step = -1;
        while (!stack.empty()) {
            int size = stack.size();
            step++;
            for (int i = 0; i < size; i++) {
                vector<int> temp(stack.front());
                stack.pop();
                int row = temp[0], col = temp[1];
                if (row > 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    check[row - 1].erase(col);
                    if (check[row - 1].empty()) check.erase(row - 1);
                    stack.push(vector<int>{row - 1, col});
                }
                if (row < rows - 1 && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    check[row + 1].erase(col);
                    if (check[row + 1].empty()) check.erase(row + 1);
                    stack.push(vector<int>{row + 1, col});
                }
                if (col > 0 && grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2;
                    check[row].erase(col - 1);
                    if (check[row].empty()) check.erase(row);
                    stack.push(vector<int>{row, col - 1});
                }
                if (col < cols - 1 && grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2;
                    check[row].erase(col + 1);
                    if (check[row].empty()) check.erase(row);
                    stack.push(vector<int>{row, col + 1});
                }
            }
        }
        if (!check.empty()) return -1;
        return step;
    }
};