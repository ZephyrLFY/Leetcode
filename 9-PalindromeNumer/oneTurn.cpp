#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (!x) return true;
        int temp, res = x;
        long ans = 0;
        while (x) {
            temp = x % 10;
            x /= 10;
            ans = ans * 10 + temp;
            if (ans > INT_MAX) return false;
        }
        return ans == res;
    }
};