#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int maxSum;
public:
    int maxPathSum(TreeNode* root) {
        maxSum = -2147483648;
        helper(root);
        return maxSum;
    }
    
    int helper(TreeNode* root) {
        int temp = 0, res = 0;
        if (root->left) {
            int left = helper(root->left);
            if (left > 0) temp += left;
            res = max(res, left);
        }
        if (root->right) {
            int right = helper(root->right);
            if (right > 0) temp += right;
            res = max(res, right);
        }
        temp += root->val;
        if (temp > maxSum) maxSum = temp;
        
        res += root->val;
        return res;
    }
};