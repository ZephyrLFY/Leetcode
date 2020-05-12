#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) return 1;
        vector<double> temp;
        if (n < 0) {
            n++;
            n = 0 - n;
            x = 1 / x;
            if (n == INT_MAX) temp.push_back(x);
            else n++;
        }
        double res = x;
        
        while (n / 2 != 0) {
            if (n % 2 != 0) temp.push_back(res);
            res *= res;
            n = n / 2;
        }
        if (!temp.empty())
            for (double tmp : temp)
                res *= tmp;
        return res;
    }
};