#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int start = 0;
        int res = 1;
        int i = 0;
        while (i < len) {
            int l_ptr = i, r_ptr = i;
            while (r_ptr < len - 1 && s[r_ptr] == s[r_ptr + 1]) ++r_ptr;
            i = r_ptr + 1;
            while (r_ptr < len - 1 && l_ptr > 0 && s[l_ptr - 1] == s[r_ptr + 1]) {
                ++r_ptr;
                --l_ptr;
            }
            int curLen = r_ptr - l_ptr + 1;
            if (curLen > res) {
                start = l_ptr;
                res = curLen;
            }
        }
        return s.substr(start, res);
    }
};

int main()
{
    string s = "sadsafasfadsadqwdasd";
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
}