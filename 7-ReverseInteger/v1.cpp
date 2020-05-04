#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x) {
            int temp = x % 10;
            x /= 10;
            res = res * 10 + temp;
            if (res > INT_MAX || res < INT_MIN) return 0;
        }
        return res;
    }
};