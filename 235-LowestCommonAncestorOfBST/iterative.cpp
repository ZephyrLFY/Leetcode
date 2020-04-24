#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int left = p->val;
        int right = q->val;

        TreeNode* node = root;
        while (node) {
            int temp = node->val;
            if (left > temp && right > temp)
                node = node->right;
            else if (left < temp && right < temp)
                node = node->left;
            else return node;
        }
        return nullptr;
    }
};