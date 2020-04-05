#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int line = matrix.size();
        for(int i = 0; i < line; i++) //转置矩阵
            for(int j = i; j < line; j++)
                swap(matrix[i][j], matrix[j][i]);
        for(int i = 0; i < line; i++) //反转每一行
            for(int j = 0; j < line / 2; j++)
                swap(matrix[i][j], matrix[i][line - j - 1]);
    }
};