#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxval = 0;
        int i = 0;
        int j = height.size() - 1;
        while(i != j) {
            maxval = max(maxval, (j - i) * min(height[i], height[j]));
            if(height[i] >= height[j]) j--;
            else i++;
        }
        return maxval;
    }
};