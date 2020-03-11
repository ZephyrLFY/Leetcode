#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.empty()) {
            if(p == ".*" || p == "") return true;
            else return false;
        }
        bool pEnd = 0;
        char pre = '0';
        int sPos,pPos = 0;
        for(; sPos < s.size(); sPos++) {
            if(pEnd) return false;
            if(s[sPos] == p[pPos] || p[pPos] == '.') {
                pPos++;
                if(pPos >= p.size()) pEnd = 1;
                else if(p[pPos] == '*') {
                    pre = s[pPos];
                    while(sPos < s.size() && s[++sPos] == pre) ;
                    pPos++;
                    if(pPos == p.size()) pEnd = 1;
                }
            }
            else if(p[pPos] == '*') return false;
            else if(pPos <= p.size() && p[pPos + 1] == '*') {
                sPos--;
                pPos += 2;
            }
            else return false;
        }
        return true;
    }
};

int main()
{
    string s;
    string p;
    // cin >> s;
    // cin >> p;
    s = "a";
    p = "ac*";
    Solution solution;
    cout << solution.isMatch(s, p) << endl;
}