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
        int temp = root->val;
        int left = p->val;
        int right = q->val;
        //利用了BST的性质
        if (left > temp && right > temp) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (left < temp && right < temp) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else return root;
    }
};