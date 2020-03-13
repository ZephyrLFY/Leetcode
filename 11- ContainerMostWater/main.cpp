#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxval = 0;
        for(int i = 0; i < height.size(); i++) {
            for(int j = i; j < height.size(); j++) {
                maxval = max(maxval, (j - i) * min(height[i], height[j]));
            }
        }
        return maxval;
    }
};