#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int temp : nums) {
            if (map.find(temp) != map.end()) map[temp] = 2;
            else map[temp] = 1;
        }
        for (int temp : nums)
            if (map[temp] == 1) return temp;
    }
};