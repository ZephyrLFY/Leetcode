#include "../cppLib.h"
#include <list>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        double res = 1;
        queue<TreeNode*> queue;
        queue.push(root);
        list<double> list;
        list.push_back(1);
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = queue.front();
                queue.pop();
                double curDep = list.front();
                list.pop_front();
                if (cur->left) {
                    queue.push(cur->left);
                    list.push_back(2 * curDep);
                }
                if (cur->right) {
                    queue.push(cur->right);
                    list.push_back(2 * curDep + 1);
                }
            }
            if (list.size() > 1) res = max(res, list.back() - list.front() + 1);
        }
        return res;
    }
};