#include "../cppLib.h"

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--])
                return isValid(s, i - 1, j) || isValid(s, i, j + 1);
        }
        return true;
    }

    bool isValid(string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};