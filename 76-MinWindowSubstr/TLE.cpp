#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int len = s.size();
        string res;
        int size = INT_MAX;
        int start = 0;
        if ((!len && !t.size()) || t.size() > len) return res;
        
        for (int i = 0; i < len; i++) {
            unordered_map<char, int> dp;
            for (char c : t) {
                if (dp.count(c)) dp[c]++;
                else dp[c] = 1;
            }
            for (int j = i; j < len; j++) {
                char cur = s[j];
                if (dp.count(cur)) {
                    dp[cur]--;
                    if (!dp[cur]) dp.erase(cur);
                }
                    
                if (dp.empty()) {
                    int curLen = j - i + 1;
                    if (curLen < size) {
                        start = i;
                        size = curLen;
                    }
                    break;
                }
            }
        }
        if (size == INT_MAX) return res;
        res = s.substr(start, size);
        return res;
    }
};