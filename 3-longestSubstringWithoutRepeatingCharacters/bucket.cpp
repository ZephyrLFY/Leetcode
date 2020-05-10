#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
/*
class Solution { //start位置开始计数，上面的写法是start之后开始计数
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len < 2) return len;
        vector<int> dict(256, -1);
        int start = 0, res = 1;
        dict[s[0]] = 0;
        for (int i = 1; i < len; ++i) {
            if (dict[s[i]] >= start) {
                res = max(res, i - start);
                start = dict[s[i]] + 1;
            }
            dict[s[i]] = i;
        }
        res = max(res, len - start);
        return res;
    }
};*/

int main()
{
    Solution solution;

    cout << solution.lengthOfLongestSubstring("abcabcacb") << endl;
    
    return 0;
}