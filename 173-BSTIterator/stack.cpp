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
    stack<int> stack;

public:
    BSTIterator(TreeNode* root) {
        helper(root);
    }

    void helper(TreeNode* root) {
        if (root == NULL) return;
        helper(root->right);
        stack.push(root->val);
        helper(root->left);
    }
    
    /** @return the next smallest number */
    int next() {
        int res = stack.top();
        stack.pop();
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (stack.empty()) return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */