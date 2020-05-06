#include "../cppLib.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false;
        int cols = matrix[0].size();
        if (cols == 0) return false;
        int low = 0, high = 0;
        
        for (int i = 0; i < rows; i++) {
            int lower = matrix[i][0];
            int upper = matrix[i][cols - 1];
            if (target == lower || target == upper) return true;
            if (upper < target) high = i + 1;
            if (lower > target) break;
            low = i;
        }
        
        for (int row = high; row <= low; row++) {
            if (binarySearch(matrix, row, 1, cols - 2, target)) return true;
        }
        return false;
    }

    bool binarySearch(vector<vector<int>>& matrix, int row, 
    int start, int end, int target) {
        if (start > end) return false;
        int mid = start + (end - start) / 2;
        int temp = matrix[row][mid];
        if (temp == target) return true;
        if (temp < target) return binarySearch(matrix, row, mid + 1, end, target);
        else return binarySearch(matrix, row, start, mid - 1, target);
    }
};