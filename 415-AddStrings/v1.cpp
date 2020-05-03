#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        vector<char> res;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int val1 = i >= 0 ? num1[i] - '0' : 0;
            int val2 = j >= 0 ? num2[j] - '0' : 0;
            int temp = val1 + val2 + carry;
            carry = 0;
            if (temp >= 10) {
                temp = temp % 10;
                carry = 1;
            }
            char foo = temp + '0';
            res.push_back(foo);
            i--;
            j--;
        }
        if (carry) res.push_back('1');
        string ans;
        for (int i = res.size() - 1; i >= 0; i--) ans.push_back(res[i]);
        return ans;
    }
};