#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (!rows) return 0;
        int cols = matrix[0].size();
        vector<int> height(cols + 2);
        int res = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '0') height[j + 1] = 0;
                else height[j + 1]++; 
            }
            res = max(res, largestRec(height));
        }
        return res;
    }

    int largestRec(vector<int>& height) {
        vector<int> stack;
        int res = 0;
        stack.push_back(0);
        for (int i = 1; i < height.size(); ++i) {
            while (height[i] < height[stack.back()]) {
                int temp = stack.back();
                stack.pop_back();
                int pre = stack.back();
                res = max(res, (i - pre - 1) * height[temp]);
            }
            stack.push_back(i);
        }
        return res;
    }
};