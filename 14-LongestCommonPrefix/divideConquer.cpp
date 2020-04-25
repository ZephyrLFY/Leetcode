#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0) return "";
        if (len == 1) return strs[0];
        return divide(strs, 0, len - 1);
    }

    string divide(vector<string>& strs, int start, int end) {
        if (start >= end) return strs[end];
        int mid = start + (end - start) / 2;
        string left = divide(strs, start, mid);
        string right = divide(strs, mid + 1, end);
        string res = "";
        int index = 0;
        while (index < left.size() && index < right.size()) {
            if (left.at(index) == right.at(index)) {
                res += left.at(index);
                index++;
            }
            else break;
        }
        return res;
    }
};