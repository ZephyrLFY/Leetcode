#include <iostream>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        int pre1 = 0;
        int pre2 = 0;
        int pre3 = 1;
        int temp;
        for (int i = 1; i < n; i++) {
            temp = pre3;
            pre3 = pre1 + pre2 + pre3;
            pre1 = pre2;
            pre2 = temp;
        }
        return pre3;
    }
};