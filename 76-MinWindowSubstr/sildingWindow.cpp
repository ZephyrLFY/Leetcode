#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        if (!len1 && !len2 || len1 < len2) return "";
        int res = INT_MAX, start = 0;
        unordered_map<char, int> map;
        unordered_map<char, int> need;
        for (char c : t) ++need[c];
        int valid = 0;
        int l = 0, r = 0;
        while (r < len1) {
            char cur = s[r];
            r++;
            if (need.count(cur)) {
                map[cur]++;
                if (need[cur] == map[cur]) valid++;
            }
            while (valid == need.size()) {
                int curLen = r - l;
                if (curLen < res) {
                    res = curLen;
                    start = l;
                }
                char temp = s[l];
                l++;
                if (need.count(temp)) {
                    if (map[temp] == need[temp])
                        valid--;
                    map[temp]--;
                }
            }
        }
        return res == INT_MAX ? "" : s.substr(start, res);
    }
};