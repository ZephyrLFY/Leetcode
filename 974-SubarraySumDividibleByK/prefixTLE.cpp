#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int len = A.size();
        vector<int> prefix(len);
        prefix[0] = A[0];
        int res = 0;
        for (int i = 1; i < len; ++i) {
            prefix[i] = prefix[i - 1] + A[i];
        }
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if ((prefix[j] - prefix[i]) % K == 0) ++res;
            }
            if (prefix[i] % K == 0) ++res;
        }
        return res;
    }
};