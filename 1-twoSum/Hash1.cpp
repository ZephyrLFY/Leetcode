#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(0);
        int i = 0;
        unordered_map<int, int> temp;
        for(i = 0; i < nums.size(); i++)
        {
            temp[nums.at(i)] = i;
        }
        for(i = 0; i < nums.size(); i++)
        {
            cout << nums.at(i) << endl;
            unordered_map<int, int>::const_iterator got = temp.find(target - nums.at(i));
            if(got != temp.end() && got->second != i)
            {
                result.resize(2);
                result[0] = i;
                result[1] = got->second;
                return result;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> input(5);
    input[0] = -1;
    input[1] = -2;
    input[2] = -3;
    input[3] = -4;
    input[4] = -5;
    Solution solu;
    vector<int> result = solu.twoSum(input,-8);
    cout << result[0] << " " << result[1] << endl;
}