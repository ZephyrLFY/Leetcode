#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int index = 0;
        int len1 = a.size() - 1, len2 = b.size() - 1;
        string res = "";
        int carry = 0;
        while (len1 - index >= 0 || len2 - index >= 0) {
            int first = (len1 - index >= 0) ? a.at(len1 - index) - '0' : 0;
            int second = (len2 - index >= 0) ? b.at(len2 - index) - '0' : 0;
            first = first + second + carry;

            char temp;
            if (first / 2 == 0) {
                temp = first + '0';
                carry = 0;
            }
            else {
                temp = first % 2 + '0';
                carry = 1;
            }
            res = temp + res;
            index++;
        }
        if (carry) res = '1' + res;
        return res;
    }
};

int main()
{
    Solution solu;
    cout << solu.addBinary("1010", "1011") << endl;
}