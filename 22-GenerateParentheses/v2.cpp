#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> *result = new vector<string>(0);
        if(n == 0) return *result;
        int left = n - 1; //剩余可以使用的左括号
        int right = n; //可以使用的右括号
        string temp = "(";
        reachKid(temp, left, result, right);
        return *result;
    }

    void reachKid(string pre, int left, vector<string> *result, int right) {
        if(left == 0 && right == 0) { //到达子节点
            result->push_back(pre);
        }
        if(left > 0) { //新建左边子节点
            reachKid(pre + '(', left - 1, result, right);
        }
        if(right > left) { //右边子节点
            reachKid(pre + ')', left, result, right - 1);
        }
    }
};

int main()
{
    Solution solu;
    int n;
    cin >> n;
    vector<string> result = solu.generateParenthesis(n);
    for(vector<string>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}