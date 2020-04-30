#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int newColor;
    int originColor;
    int rows;
    int cols;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        rows = image.size();
        if (rows == 0) return image;
        cols = image[0].size();
        originColor = image[sr][sc];
        this->newColor = newColor;
        if (newColor == originColor) return image;
        dfs(image, sr, sc);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc) {
        image[sr][sc] = newColor;
        if (sr < rows - 1 && image[sr + 1][sc] == originColor) dfs(image, sr + 1, sc);
        if (sr > 0 && image[sr - 1][sc] == originColor) dfs(image, sr - 1, sc);
        if (sc > 0 && image[sr][sc - 1] == originColor) dfs(image, sr, sc - 1);
        if (sc < cols - 1 && image[sr][sc + 1] == originColor) dfs(image, sr, sc + 1);
    }
};