#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> res(len);
        if (len == 0) return res;
        stack<int> index;
        for (int i = 0; i < len; i++) {
            while (!index.empty() && T[i] > T[index.top()]) {
                cout << T[i] << endl;
                int temp = index.top();
                index.pop();
                res[temp] = i - temp;
            }
            index.push(i);
        }
        while (!index.empty()) {
            int temp = index.top();
            res[temp] = 0;
            index.pop();
        }
        return res;
    }
};