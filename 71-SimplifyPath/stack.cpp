#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size(), i = 0, j = 0;
        vector<string> stack;
        while (j < len) {
            if (path[j] == '/') {
                if (stack.empty() || stack.back() != "/") {
                    stack.push_back("/");
                }
                ++j;
            }
            else {
                string curStr = "";
                while (j < len && path[j] != '/') {
                    curStr += path[j++];
                }
                if (curStr == "..") {
                    if (stack.size() > 1) {
                        stack.pop_back();
                        stack.pop_back();
                    }
                }
                else if (curStr != ".") stack.push_back(curStr);
            }
            i = j;
        }
        string res;
        if (stack.size() > 1 && stack.back() == "/") stack.pop_back();
        while (!stack.empty()) {
            res = stack.back() + res;
            stack.pop_back();
        }
        return res;
    }
};