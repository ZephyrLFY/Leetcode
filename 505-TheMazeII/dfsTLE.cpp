#include "../cppLib.h"

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        distance[start[0]][start[1]] = 0;
        dfs(maze, start, distance);
        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }

    void dfs(vector<vector<int>>& maze, vector<int>& start, vector<vector<int>>& distance) {
        vector<vector<int>> choose = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        for (auto next : choose) {
            int x = start[0] + next[0];
            int y = start[1] + next[1];
            int count = 0;
            while (x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0) {
                x += next[0];
                y += next[1];
                ++count;
            }
            if (distance[start[0]][start[1]] + count < distance[x - next[0]][y - next[1]]) {
                distance[x - next[0]][y - next[1]] = distance[start[0]][start[1]] + count;
                vector<int> temp = {x - next[0], y - next[1]};
                dfs(maze, temp, distance);
            }
        }
    }
};