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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);     // 如果key大于root->val， 递归到右子树删除
            return root;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);       // 如果key小于root->val， 递归到左子树删除
            return root;
        }
        if (!root->left) {
            TreeNode* tmp = root->right;   // 如果key = root->val，且左子为null，根变成右子根
            delete root;
            return tmp;
        }
        if (!root->right) {
            TreeNode* tmp = root->left;    // 如果key = root->val, 且右子为null，根变成左子根
            delete root;
            return tmp;
        }
        TreeNode* tmp = root->right;
        while (tmp->left) tmp = tmp->left; // 找到右子树中最小值，与root->val交换
        swap(root->val, tmp->val);
        root->right = deleteNode(root->right, key);  // 再在交换过的树中删除key
        return root;
    }
};

int main()
{
    Solution solu;
    TreeNode* root = new TreeNode(9);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(8);
    TreeNode* res = solu.deleteNode(root, 5);
    //cout << (root == NULL) << endl;
    return 0;
}