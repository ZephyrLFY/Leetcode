#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 2) return false;
        int pre = 1, sum = 1;
        for (int i = 2; i * i <= num; i++) { //sqrt(num)为界
            if (num % i == 0) {
                sum += i;
                if (i * i != num) sum += num / i;
            }
        }
        return sum == num;
    }
};