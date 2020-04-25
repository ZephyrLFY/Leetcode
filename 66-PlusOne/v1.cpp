#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        vector<int> res(len);
        int carry = 1;
        for (int index = len - 1; index >= 0; index--) {
            int temp = digits[index] + carry;
            if (temp / 10 == 1) {
                carry = 1;
                res[index] = temp % 10;
            }
            else {
                carry = 0;
                res[index] = temp;
            }
        }
        if (carry == 1) res.insert(res.begin(), 1);
        return res;
    }
};