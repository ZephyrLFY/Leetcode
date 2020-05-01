#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) return res;
        return helper(1, n);
    }

    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        if (start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTree = helper(start, i - 1);
            vector<TreeNode*> rightTree = helper(i + 1, end);
            for (TreeNode* left : leftTree)
                for (TreeNode* right : rightTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
        }
        return res;
    }
};