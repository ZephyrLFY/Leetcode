#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (!rows) return -1;
        int cols = grid[0].size();
        vector<vector<int>> check;
        queue<vector<int>> stack;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) check.push_back(vector<int>{i, j});
                else if (grid[i][j] == 2) stack.push(vector<int>{i, j});
            }
        }
        int step = 0;
        while (!stack.empty()) {
            int size = stack.size();
            step++;
            for (int i = 0; i < size; i++) {
                vector<int> temp(stack.front());
                stack.pop();
                if (temp[0] > 0 && grid[temp[0] - 1][temp[1]] == 1) {
                    grid[temp[0] - 1][temp[1]] = 2;
                    stack.push(vector<int>{temp[0] - 1, temp[1]});
                }
                if (temp[0] < rows - 1 && grid[temp[0] + 1][temp[1]] == 1) {
                    grid[temp[0] + 1][temp[1]] = 2;
                    stack.push(vector<int>{temp[0] + 1, temp[1]});
                }
                if (temp[1] > 0 && grid[temp[0]][temp[1] - 1] == 1) {
                    grid[temp[0]][temp[1] - 1] = 2;
                    stack.push(vector<int>{temp[0], temp[1] - 1});
                }
                if (temp[1] < cols - 1 && grid[temp[0]][temp[1] + 1] == 1) {
                    grid[temp[0]][temp[1] + 1] = 2;
                    stack.push(vector<int>{temp[0], temp[1] + 1});
                }
            }
        }
        for (auto temp : check) {
            if (grid[temp[0]][temp[1]] == 1) return -1;
        }
        return step;
    }
};