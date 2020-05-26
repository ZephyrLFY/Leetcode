#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> left(len);
        vector<int> right(len);
        int res = 0;
        for (int i = 1; i < len; ++i) {
            if (ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1;
        }
        for (int i = len - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) right[i] = right[i + 1] + 1;
        }
        for (int i = 0; i < len; ++i) {
            res += max(left[i], right[i]);
        }
        return res + len;
    }
};