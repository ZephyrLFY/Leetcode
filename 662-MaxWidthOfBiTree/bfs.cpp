#include "../cppLib.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        if (!root) return res;
        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            int size = queue.size();
            if (size > res) res = size;
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = queue.front();
                queue.pop_front();
                queue.push_back(cur ? cur->left : nullptr);
                queue.push_back(cur ? cur->right : nullptr);
            }
            while (!queue.empty() && !queue.back()) queue.pop_back();
            while (!queue.empty() && !queue.front()) queue.pop_front();
        }
        return res;
    }
};