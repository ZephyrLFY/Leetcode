#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int N) {
        int fib1 = 0, fib2 = 1;
        if (N == 0) return 0;
        if (N == 1) return 1;
        for (int i = 2; i <= N; i++) {
            int temp = fib2;
            fib2 += fib1;
            fib1 = temp;
        }
        return fib2;
    }
};