#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int plen = prices.size();
        int maxpro = 0;
        for(int i = 0; i < plen - 1; ++i){
            maxpro += max(0, prices[i + 1] - prices[i]);
        }
        return maxpro;
    }
};