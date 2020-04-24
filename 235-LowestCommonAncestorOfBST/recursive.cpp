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
    TreeNode* res;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lCA(root, p, q);
        return res;
    }

    bool lCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool left = lCA(root->left, p, q);
        bool right = lCA(root->right, p, q);
        if (((root == p ^ root == q) && left ^ right) || (left && right)) {
            res = root;
            return true;
        }
        return root == p || root == q || left || right;
    }
};