#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        //利用到了同余性质，即：
        //(prefix[j] - prefix[i - 1]) % K == 0, 当且仅当prefix[j] % K == prefix[i - 1] % K
        //所以用hashmap记录下来各前缀和中，mod K得到的答案为n的有几组，然后每次对于新的j，算出prefix[j] % K的值，去hash中找答案即可
        unordered_map<int, int> record = {{0, 1}};
        int sum = 0, ans = 0;
        for (int elem: A) {
            sum += elem;
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            int modulus = (sum % K + K) % K;
            if (record.count(modulus)) {
                ans += record[modulus];
            }
            ++record[modulus];
        }
        return ans;
    }
};