#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* pre;
    TreeNode* res1;
    TreeNode* res2;
public:
    void recoverTree(TreeNode* root) {
        pre = new TreeNode(INT_MIN);
        res1 = nullptr;
        res2 = nullptr;
        helper(root);
        swap(res1->val, res2->val);
    }

    void helper(TreeNode* root) {
        if (root == nullptr) return;
        helper(root->left);
        if (pre->val > root->val) {
            if (!res1) res1 = pre;
            res2 = root;
        }
        pre = root;
        helper(root->right);
    }
};

int main()
{
    Solution solu;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    solu.recoverTree(root);
    cout << root->val << endl;
}