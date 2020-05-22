#include <iostream>
using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40) return 1 + num % 10;
            num = (num - 40 - 1) * 7 + rand7();
            if (num <= 60) return 1 + num % 10;
            num = (num - 60 - 1) * 7 + rand7();
            if (num <= 20) return 1 + num % 10;
        }
    }
};