#include "../cppLib.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false;
        int cols = matrix[0].size();
        if (cols == 0) return false;
        return divide(matrix, rows, 0, cols - 1, target);
    }

    bool divide(vector<vector<int>>& matrix, int rows, int row, int col, int target) {
        if (row >= rows || col < 0) return false;
        int temp = matrix[row][col];
        if (target == temp) return true;
        if (target > temp) return divide(matrix, rows, row + 1, col, target);
        return divide(matrix, rows, row, col - 1, target);
    }
};