#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //先进行排序，这样方便后续剪枝
        sort(candidates.begin(), candidates.end());
        DFS(candidates, 0, target);
        return result;
    }
    
    void DFS(vector<int>& candidates, int begin, int target) {
        if(target == 0) {
            result.push_back(path); //树的子节点，target正好实现，压入结果集
            return;
        }
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            //这里target >= candidates[i]是为了剪枝，无需进行后面更大的数的循环
            path.push_back(candidates[i]);
            DFS(candidates, i, target - candidates[i]);
            path.pop_back(); // 回溯
        }
    }

private:
    vector<int> path;
    vector<vector<int> > result;
};

int main()
{
    Solution solu;
    vector<int> nums = {2,3,6,7};
    int target = 7;
    solu.combinationSum(nums, target);
    //solu.showResults();
    return 0;
}