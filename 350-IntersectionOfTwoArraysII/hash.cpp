#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, int> temp;
    vector<int> res;
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums1) {
            if (temp.find(num) != temp.end()) temp[num]++;
            else temp[num] = 1;
        }
        for (int num : nums2) {
            if (temp.find(num) != temp.end()) {
                if (temp[num]-- > 0) res.push_back(num);
            }
        }
        return res;
    }
};