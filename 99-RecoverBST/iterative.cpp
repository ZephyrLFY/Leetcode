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
    stack<TreeNode*> stack;
public:
    void recoverTree(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode* pre = new TreeNode(INT_MIN);
        TreeNode* res1 = nullptr;
        TreeNode* res2 = nullptr;

        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (!res1 && pre->val > root->val)
                res1 = pre;
            if (res1 && pre->val > root->val)
                res2 = root;
            pre = root;
            root = root->right;
        }
        swap(res1->val, res2->val);
        return;
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