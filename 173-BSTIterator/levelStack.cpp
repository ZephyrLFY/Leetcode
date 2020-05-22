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
    vector<TreeNode*> stack;
public:
    BSTIterator(TreeNode* root) {
        if (!root) return;
        if (root->left) helper(root);
        else stack.push_back(root);
    }
    
    void helper(TreeNode* root) {
        while (root->left) {
            stack.push_back(root);
            root = root->left;
        }
        stack.push_back(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* cur = stack.back();
        stack.pop_back();
        if (cur->right) helper(cur->right);
        return cur->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */