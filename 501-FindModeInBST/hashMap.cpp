#include <iostream>
#include <unordered_map>
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
    unordered_map<int, int> map;
    int maxNum;
public:
    vector<int> findMode(TreeNode* root) {
        maxNum = 1;
        traverse(root);
        for (auto it : map) {
            if (it.second == maxNum) res.push_back(it.first);
        }
        return res;
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        traverse(root->left);
        traverse(root->right);
        if (map.find(root->val) == map.end()) {
            map[root->val] = 1;
        } else {
            int temp = map[root->val] + 1;
            map[root->val] = temp;
            maxNum = max(maxNum, temp);
        }
    }
};