#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (!n) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        double cur = n > 0 ? x : 1 / x;
        x *= x;
        if (n % 2) return cur * myPow(x, n / 2);
        return myPow(x, n / 2);
    }
};