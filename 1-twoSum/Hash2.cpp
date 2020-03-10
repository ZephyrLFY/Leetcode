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
            unordered_map<int, int>::const_iterator got = temp.find(target - nums.at(i));
            if(got != temp.end())
            {
                result.resize(2);
                if(i < got->second)
                {
                    result[0] = i;
                    result[1] = got->second;
                }
                else
                {
                    result[0] = got->second;
                    result[1] = i;
                }
                return result;
            }
            temp[nums.at(i)] = i;
        }
        return result;
    }
};

int main()
{
    vector<int> input(2);
    input[0] = 3;
    input[1] = 3;
    // input[2] = -3;
    // input[3] = -4;
    // input[4] = -5;
    Solution solu;
    vector<int> result = solu.twoSum(input,6);
    cout << result[0] << " " << result[1] << endl;
}