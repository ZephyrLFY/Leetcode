#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, top = 0;
        int len = height.size();
        stack<int> temp;
        for(int i = 0; i < len; i++) {
            while(!temp.empty() && height[i] > height[temp.top()]) {
                top = temp.top();
                temp.pop();
                if(temp.empty()) break; //前面的清空，重新开始
                sum += (min(height[i], height[temp.top()]) - height[top]) * (i - temp.top() - 1);
            }
            temp.push(i);
        }
        return sum;
    }
};