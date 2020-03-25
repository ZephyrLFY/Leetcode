#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, maxL = 0, maxR = 0;
        int len = height.size();
        for(int i = 1; i < len - 1; i++) {
            for(int j = i; j >= 0; j--) maxL = max(maxL, height[j]);
            for(int k = i; k < len; k++) maxR = max(maxR, height[k]);
            sum += min(maxL, maxR) - height[i];
            maxR = 0;
            maxL = 0;
        }
        return sum;
    }
};