#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stack;
        for (int i = 0; i < s.size(); i++) {
            char temp = s[i];
            if (temp == '(') stack.push_back(i);
            else if (temp == ')') {
                if (!stack.empty() && s[stack.back()] == '(') stack.pop_back();
                else stack.push_back(i);
            }
        }
        int offset = 0;
        for (int temp : stack) {
            s.erase(temp - offset, 1);
            offset++;
        }
        return s;
    }
};