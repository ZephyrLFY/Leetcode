#include "../cppLib.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<int, int> map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        for (int i = 0; i < len; ++i) {
            map[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, len - 1, 0, len - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if (ps > pe) return nullptr;
        int rootVal = preorder[ps];
        int index = map[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        root->left = helper(preorder, inorder, ps + 1, ps + index - is, is, index - 1);
        root->right = helper(preorder, inorder, ps + 1 + index - is, pe, index + 1, ie);
        return root;
    }
};