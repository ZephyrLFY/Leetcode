#include "../cppLib.h"

class Solution {
private:
    unordered_set<string> hash;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (string temp : wordDict) hash.insert(temp);
        return dfs(s, 0);
    }
    
    bool dfs(string& s, int start) {
        if (start == s.size()) return true;
        int scan = start;
        bool status = false;
        while (scan < s.size()) {
            if (hash.count(s.substr(start, scan - start + 1)))
                status = status || dfs(s, scan + 1);
            scan++;
        }
        return status;
    }
};