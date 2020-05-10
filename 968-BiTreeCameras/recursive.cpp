#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res = 0;
        int last = helper(root, res);
        if (!last) ++res;
        return res;
    }
    

    //return state : 0,1,2
    //0: not monitored; 1: monitored; 2: has a camera
    int helper(TreeNode* root, int& res) {
        if (!root) return 1;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        if (left == 1 && right == 1) return 0;
        if (!left || !right) {
            ++res;
            return 2;
        }
        return 1;
    }
};