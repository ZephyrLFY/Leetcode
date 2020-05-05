#include "../cppLib.h"

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.empty()) return true;
        int i = 0, j = s.size() - 1;
        int first = -1, second = -1;
        while (i <= j) {
            if (s[i] != s[j]) {
                first = i;
                second = j;
                break;
            }
            i++;
            j--;
        }
        if (first == -1) return true;
        return isValid(s.substr(0, i) + s.substr(i + 1, s.size() - i - 1)) || isValid(s.substr(0, j) + s.substr(j + 1, s.size() - j - 1));
    }

    bool isValid(string s) {
        if (s.empty()) return true;
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};