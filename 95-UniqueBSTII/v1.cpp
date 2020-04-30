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
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        for (TreeNode* temp : generateTrees(n - 1)) {
            TreeNode* root = new TreeNode(n);
            if (temp->val < )
        }
    }
};