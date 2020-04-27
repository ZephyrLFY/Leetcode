#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
private:
    unordered_set<int> visited;
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        else if (visited.find(n) != visited.end()) return false;
        else {
            visited.insert(n);
            int temp = 0;
            while (n / 10 != 0) {
                int bit = n % 10;
                temp += bit * bit;
                n = n / 10;
            }
            if (n != 0) temp += n * n;
            return isHappy(temp);
        }
    }
};