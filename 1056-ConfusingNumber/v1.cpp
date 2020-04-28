#include <iostream>
using namespace std;

class Solution {
public:
    bool confusingNumber(int N) {
        string num = to_string(N);
        string w = "";
        for (int i = num.length() - 1; i >= 0; i--) {
            if (num[i] == '1') w += num[i];
            else if (num[i] == '8') w += num[i];
            else if (num[i] == '0') w += num[i];
            else if (num[i] == '6') w += '9';
            else if (num[i] == '9') w += '6';
            else return false;
        }
        if (w == num) return false;
        return true;
    }
};