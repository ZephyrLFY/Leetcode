#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        long left = 1, right = x - 1;
        while (left < right - 1) { //注意，死循环
            long mid = left + (right - left) / 2;
            long temp = mid * mid;
            if (x > temp) left = mid;
            else if (x < temp) right = mid;
            else return mid;
        }
        return left;
    }
};