#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int i = 1, j = 2;
        int sum = 3; //左闭右闭

        while (i <= target / 2) {
            if (sum < target) {
                j++;
                sum += j;
            }
            else if (sum > target) {
                sum -= i;
                i++;
            }
            else {
                vector<int> temp;
                for (int k = i; k <= j; k++)
                    temp.push_back(k);
                res.push_back(temp);

                j++;
                sum = sum - i - i - 1 + j;
                i += 2;
            }
        }
        return res;
    }
};