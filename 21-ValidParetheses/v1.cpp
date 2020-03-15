#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len % 2 != 0) return false;
        stack<char> temp;
        for(int i = 0; i < len; i++) {
            if(s[i] == '[' || s[i] == '(' || s[i] == '{') temp.push(s[i]);
            else {
                if(!temp.empty() && (temp.top() == s[i] - 1 || temp.top() == s[i] - 2))
                  temp.pop();
              	else return false;
            }
        }
        if(temp.empty()) return true;
        else return false;
    }
};