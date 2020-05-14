#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int maxSum;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        path(root);
        return maxSum;
    }
    
    int path(TreeNode* root) {
        int sum = 0;
        int left = 0, right = 0;
        if (root->left) {
            left = path(root->left);
            sum += left;
        }
        if (root->right) {
            right = path(root->right);
            sum += right;
        }
        if (sum > maxSum) maxSum = sum;
        return max(left, right) + 1;
    }
};