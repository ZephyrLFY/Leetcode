#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> res;
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }

    void dfs(string& s, int begin) {
        if (begin >= s.size()) {
            res.push_back(s);
            return;
        }

        for (int i = begin; i < s.size(); i++) {
            bool seen = false;
            for (int j = begin; j < i; j++) {
                if (s[j] == s[i]) seen = true;
            }
            if (seen) continue;
            swap(s[begin], s[i]);
            dfs(s, begin + 1);
            swap(s[begin],s[i]);
        }
    }
};