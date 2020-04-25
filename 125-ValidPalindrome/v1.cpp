#include <iostream>
using namespace std;

class Solution {
public:
    //重点: islower(), isdight(), isupper(), isalnum()
    bool isPalindrome(string s) {
        string tmp;
        for (auto c : s) {
            if (islower(c) || isdigit(c))  tmp += c;
            else if (isupper(c)) tmp += (c + 32);
        }
        int i = 0, j = tmp.size() - 1;
        while (i < j) {
            if (tmp[i] != tmp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};