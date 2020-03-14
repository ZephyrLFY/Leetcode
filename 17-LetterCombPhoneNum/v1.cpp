#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        nums['2'] = {"a", "b", "c"};
        nums['3'] = {"d", "e", "f"};
        nums['4'] = {"g", "h", "i"};
        nums['5'] = {"j", "k", "l"};
        nums['6'] = {"m", "n", "o"};
        nums['7'] = {"p", "q", "r", "s"};
        nums['8'] = {"t", "u", "v"};
        nums['9'] = {"w", "x", "y", "z"};
        return combine(digits);
    }
    vector<string> combine(string digits) {
        if(digits.length() == 1) return nums[digits[0]];
        else if(digits.length() == 0) return pre;
        else {
            char temp = digits[digits.size() - 1];
            digits.pop_back();
            vector<string> cur = combine(digits);
            pre.resize(cur.size() * nums[temp].size());
            int times = 0;
            for(int i = 0; i < cur.size(); i++) {
                for(int j = 0; j < nums[temp].size(); j++) {
                    pre[times] = cur[i] + nums[temp][j];
                    times++;
                }
            }
            return pre;
        }
    }
private:
    unordered_map<char, vector<string> > nums;
    vector<string> pre;
};

int main()
{
    Solution solu;
    string nums;
    //cin >> nums;
    nums = {};
    vector<string> result = solu.letterCombinations(nums);
    for(vector<string>::iterator it = result.begin(); it != result.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}