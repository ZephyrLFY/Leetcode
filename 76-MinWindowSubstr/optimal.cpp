#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int count[125] = { 0 };
        for (auto c : t) ++count[c];
        int len = 0, minLength = s.length();
        string res;
        for (int l = 0, r = 0; r < s.length(); ++r) {
            count[s[r]]--;
            if (count[s[r]] >= 0) ++len;
            while (len == t.length()) {
                if (r - l + 1 <= minLength) {
                    minLength = r - l + 1;
                    res = s.substr(l, r - l + 1);
                }
                count[s[l]]++;
                if (count[s[l]] > 0) --len;
                ++l;
            }
        }
        return res;
    }
};