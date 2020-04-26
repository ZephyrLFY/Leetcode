#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res(0);
        int rows = matrix.size();
        if (rows == 0) return res;
        int cols = matrix[0].size();

        int i = 0;
        while (i < rows + cols - 1) {
            int x1 = i < rows ? i : rows - 1;
            int y1 = i - x1;
            while (x1 >= 0 && y1 < cols)
                res.push_back(matrix[x1--][y1++]);
            i++;
            if (i >= rows + cols - 1) break;
            int y2 = i < cols ? i : cols - 1;
            int x2 = i - y2;
            while (y2 >= 0 && x2 < rows)
                res.push_back(matrix[x2++][y2--]);
            i++;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<vector<int>> matrix(0);
    vector<int> nums1 = {1,2,3,1};
    vector<int> nums2 = {4,5,6,2};
    // vector<int> nums3 = {7,8,9,1};
    // vector<int> nums4 = {7,8,9,2};
    matrix.push_back(nums1);
    matrix.push_back(nums2);
    // matrix.push_back(nums3);
    // matrix.push_back(nums4);
    vector<int> res = solu.findDiagonalOrder(matrix);
    for (int temp : res) {
        cout << temp << " ";
    }
    cout << endl;
}