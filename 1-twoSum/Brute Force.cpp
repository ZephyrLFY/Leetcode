#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(0);
        int i = 0;
        int j = 0;
        for(; i < nums.size(); i++)
        {
            for(j = i + 1; j < nums.size(); j++)
            {
                if(nums.at(i) + nums.at(j) == target)
                {
                    result.resize(2);
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
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