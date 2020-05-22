#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        deque<TreeNode*> queue;
        queue.push_back(root);
        bool left = true;
        while (!queue.empty()) {
            int size = queue.size();
            vector<int> temp(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = left ? queue.front() : queue.back();
                if (left) queue.pop_front();
                else queue.pop_back();
                temp[i] = cur->val;
                if (left) {
                    if (cur->left) queue.push_back(cur->left);
                    if (cur->right) queue.push_back(cur->right);
                }
                else {
                    if (cur->right) queue.push_front(cur->right);
                    if (cur->left) queue.push_front(cur->left);
                }
                
            }
            left = !left;
            res.push_back(temp);
        }
        return res;
    }
};