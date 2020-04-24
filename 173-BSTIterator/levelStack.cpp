#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> stack;

public:
    BSTIterator(TreeNode* root) {
        if (root == NULL) return;
        if (root->left != NULL)
            helper(root);
        else stack.push(root);
    }

    void helper(TreeNode* root) {
        while (root->left != NULL) {
            stack.push(root);
            root = root->left;
        }
        stack.push(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* temp = stack.top();
        int res = temp->val;
        stack.pop();
        if (temp->right != NULL)
            helper(temp->right);
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (stack.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */