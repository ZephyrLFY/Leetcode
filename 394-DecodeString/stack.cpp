#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        vector<int> times;
        vector<string> stack;
        int tempNum = 0;
        string tempStr = "";
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                tempNum = tempNum * 10 + s[i] - '0';
            }
            else if (s[i] == '[') {
                stack.push_back(tempStr);
                tempStr.clear();
                times.push_back(tempNum);
                tempNum = 0;
            }
            else if (s[i] == ']') {
                string pre = stack.back();
                stack.pop_back();
                int rep = times.back();
                times.pop_back();
                for (int i = 0; i < rep; i++) {
                    pre += tempStr;
                }
                tempStr = pre;
            }
            else {
                tempStr += s[i];
            }
        }
        
        return tempStr;
    }
};