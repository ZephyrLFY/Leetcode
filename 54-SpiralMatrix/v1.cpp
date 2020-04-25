#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> res;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 用r1, r2, c1, c2卡住四个角
        int len = matrix.size();
        if (len == 0) return res;
        int r1 = 0, r2 = len - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;
        while (r1 <= r2 && c1 <= c2) {
            for (int c = c1; c <= c2; c++) res.push_back(matrix[r1][c]);
            for (int r = r1 + 1; r <= r2; r++) res.push_back(matrix[r][c2]);
            if (r1 < r2 && c1 < c2) {
                for (int c = c2 - 1; c > c1; c--) res.push_back(matrix[r2][c]);
                for (int r = r2; r > r1; r--) res.push_back(matrix[r][c1]);
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<vector<int>> matrix;
    vector<int> nums1 = {1};
    matrix.push_back(nums1);
    vector<int> nums2 = {2};
    matrix.push_back(nums2);
    vector<int> nums3 = {3};
    matrix.push_back(nums3);
    vector<int> nums4 = {4};
    matrix.push_back(nums4);
    vector<int> nums5 = {5};
    matrix.push_back(nums5);
    // vector<int> nums6 = {6};
    // matrix.push_back(nums6);
    // vector<int> nums7 = {7};
    // matrix.push_back(nums7);
    // vector<int> nums8 = {8};
    // matrix.push_back(nums8);

    // vector<int> nums4 = {13,14,15,16};
    // matrix.push_back(nums4);
    vector<int> res = solu.spiralOrder(matrix);
    for (int temp : res) cout << temp << " ";
    cout << endl;
}