#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        string res;
        int size = INT_MAX;
        int start = 0;
        if ((!len1 && !len2) || len2 > len1) return res;
        unordered_map<char, int> dp;
        unordered_map<char, int> need;
        for (char c : t) need[c]++;
        
        int valid = 0;
        int l = 0, r = 0;
        while (r < len1) {
            char cur = s[r];
            r++;
            if (need.count(cur)) {
                dp[cur]++;
                if (need[cur] == dp[cur]) valid++;
            }
            if (valid == need.size()) {
                int curLen = r - l;
                if (curLen < size) {
                    size = curLen;
                    start = l;
                }
                while (l <= len2 - len1 && valid == need.size()) {
                    char temp = s[l];
                    if (need.count(temp)) {
                        dp[temp]--;
                        if (!dp[temp]) valid--;
                    }
                    l++;
                }
                if (l > len2 - len1) break;
            }
        }
        if (size != INT_MAX) {
            res = s.substr(start, size);
        }
        return res;
    }
};