#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int start = 0, end = len - 1;
        vector<int> res(2);
        while (start < end) {
            if (numbers[start] + numbers[end] < target) start++;
            else if (numbers[start] + numbers[end] > target) end--;
            else {
                res[0] = start + 1;
                res[1] = end + 1;
                break;
            }
        }
        return res;
    }
};