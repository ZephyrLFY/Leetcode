#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> res;
    int pre;
    int cur;
    int curSum;
    int maxSum;
public:
    vector<int> findMode(TreeNode* root) {
        maxSum = 1;
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        traverse(root->left);
        cur = root->val;
        if (curSum && cur == pre) curSum++;
        else {
            pre = cur;
            curSum = 1;
        }

        if (curSum > maxSum) {
            res.clear();
            maxSum = curSum;
            res.push_back(cur);
        }
        else if (curSum == maxSum) {
            res.push_back(cur);
        }
        traverse(root->right);
    }
};