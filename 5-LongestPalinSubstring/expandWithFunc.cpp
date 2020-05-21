#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len == 1) { 
            return s;
        }
        int start = 0;
        int end = 0;
        int mlen = 0;

        for(int i = 0; i < len; i++) {
            int len1 = expendaroundcenter(s, i, i);
            int len2 = expendaroundcenter(s, i, i + 1);
            mlen = max(max(len1, len2), mlen);
            if(mlen > end - start + 1) {
                start = i - (mlen - 1)/2;
                end = i + mlen/2;
            }
        }
        return s.substr(start, mlen);
    }
    private:
    int expendaroundcenter(string s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

int main()
{
    string s = "sadsafasfadsadqwdasd";
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
}