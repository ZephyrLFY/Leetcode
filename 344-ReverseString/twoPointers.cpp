#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if (len <= 1) return;
        int start = 0, end = len - 1;
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }
};