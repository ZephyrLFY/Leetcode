#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        long res = 0;
        bool positive = true;
        int i = 0;
        while (str[i] == ' ') {i++;}
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+') return 0;
        if (!isdigit(str[i])) {
            if (str[i] == '-') positive = false;
            i++;
        }
        while (i < len && isdigit(str[i])) {
            if (positive) {
                res = res * 10 + str[i++] - '0';
                if (res > INT_MAX) return INT_MAX;
            }
            else {
                res = res * 10 - (str[i++] - '0');
                if (res < INT_MIN) return INT_MIN;
            }
            
        }
        return res;
    }
};