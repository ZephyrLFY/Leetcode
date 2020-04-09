#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        if(m < n) std::swap(m, n);
        unsigned long long int res = 1, divide = 1;
        for(int i = m; i <= m + n - 2; i++) res *= i;
        for(int i = 2; i <= n - 1; i ++) divide *= i;
        return res / divide;
    }
};