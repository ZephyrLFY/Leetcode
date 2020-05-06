#include "../cppLib.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            int size = stack.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = stack.front();
                stack.pop();
                if (i == size - 1) ans.push_back(temp->val);
                if (temp->left) stack.push(temp->left);
                if (temp->right) stack.push(temp->right);
            }
        }
        
        return ans;
    }
};