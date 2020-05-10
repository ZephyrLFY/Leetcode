#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') stack.push_back(i);
            else if (s[i] == ')') {
                if (!stack.empty() && s[stack.back()] == '(') stack.pop_back();
                else stack.push_back(i);
            }
        }
        for (int i = stack.size() - 1; i >= 0; --i) {
            s.erase(stack[i], 1);
        }
        return s;
    }
};