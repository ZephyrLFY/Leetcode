#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len <= 1) return len;
        int res = 1;
        unordered_map<int,int> seen;
        int i = 0, j = 0;
        while (j < len) {
            char cur = s[j];
            if (seen.count(cur)) {
                res = max(res, j - i);
                while (seen.count(cur)) {
                    seen[s[i]]--;
                    if (!seen[s[i]]) seen.erase(s[i]);
                    i++;
                }    
            }
            seen[cur] = 1;
            j++;
        }
        res = max(res, j - i);
        return res;
    }
};

int main()
{
    Solution solution;

    cout << solution.lengthOfLongestSubstring("abcdefgh") << endl;
    
    return 0;
}