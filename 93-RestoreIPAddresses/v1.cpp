#include "../cppLib.h"
using namespace std;

class Solution {
private:
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        if (len < 4 || len > 12) return res;
        dfs(s, 0, len - 3, 3);
        return res;
    }

    void dfs(string s, int start, int most, int left) {
        int len = s.size();
        if (!left) {
            if (isValid(s))
                res.push_back(s);
            return;
        }
        for (int i = 1; i <= most; i++) {
            int pos = start + i;
            if (pos >= len) return;
            string cur = s;
            cur.insert(pos, ".");
            dfs(cur, pos + 1, most, left - 1);
        }
    }

    bool isValid(string s) {
        int len = s.size();
        int i = 0;
        while (i < len) {
            int j = i;
            while (j < len && s[j] != '.') j++;
            if (j - i + 1 > 2 && s[i] == '0') return false;
            int temp = atoi(s.substr(i, j - i + 1).c_str());
            if (temp < 0 || temp > 255) return false;
            j++;
            i = j;
        }
        return true;
    }
};