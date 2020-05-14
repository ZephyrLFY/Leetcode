#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<int, int> map;
    vector<vector<int>> unorderedRes;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<TreeNode*> que;
        queue<int> verti;
        if (!root) return unorderedRes;
        que.push(root);
        verti.push(0);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = que.front();
                int curVer = verti.front();
                que.pop();
                verti.pop();
                if (map.count(curVer)) unorderedRes[map[curVer]].push_back(cur->val);
                else {
                    vector<int> temp = {cur->val};
                    unorderedRes.push_back(temp);
                    map[curVer] = unorderedRes.size() - 1;
                }
                if (cur->left) {
                    que.push(cur->left);
                    verti.push(curVer - 1);
                }
                if (cur->right) {
                    que.push(cur->right);
                    verti.push(curVer + 1);
                }
            }
        }
        vector<vector<int>> res;
        for (auto& it : map) {
            res.push_back(unorderedRes[it.second]);
        }
        return res;
    }
};