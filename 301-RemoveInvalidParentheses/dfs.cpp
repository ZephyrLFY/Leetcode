#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<string> res;
    unordered_set<string> seen;
public:
    vector<string> removeInvalidParentheses(string s) {
        int len = s.size();
        int leftR = 0, rightR = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') leftR++;
            else if (s[i] == ')') {
                if (leftR > 0) leftR--;
                else rightR++;
            }
        }
        helper(s, 0, 0, leftR, rightR, 0);
        return res;
    }
    
    void helper(string s, int left, int right, int leftR, int rightR, int index) {
        if (!leftR && !rightR) {
            if (isValid(s) && !seen.count(s)) {
                res.push_back(s);
                seen.insert(s);
            }
            return;
        }
        
        while (index < s.size() && s[index] != '(' && s[index] != ')') index++;
        if (index >= s.size()) return;
        if (s[index] == '(') {
            helper(s, left + 1, right, leftR, rightR, index + 1);
            if (leftR > 0) helper(s.erase(index, 1), left, right, leftR - 1, rightR, index);
        }
        else {
            if (right < left) helper(s, left, right + 1, leftR, rightR, index + 1);
            if (rightR > 0) helper(s.erase(index, 1), left, right, leftR, rightR - 1, index);
        }
    }
    
    bool isValid(string& s) {
        vector<char> stack;
        for (auto c : s) {
            if (c == '(') stack.push_back(c);
            else if (c == ')') {
                if (stack.empty() || stack.back() != '(') return false;
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};