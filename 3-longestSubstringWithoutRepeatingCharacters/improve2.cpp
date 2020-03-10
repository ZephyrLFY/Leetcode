#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        //滑动窗口的开始与结束
        int startIndex = 0;
        int endIndex = 0;

        //傻逼输入处理
        if(!len)
            return 0;

        int result = 1;
        int count = 0;

        unordered_map <char, int> temp;
        while(startIndex < len && endIndex < len) {
            if(temp.find(s.at(endIndex)) == temp.end()) {
                temp.insert(make_pair(s.at(endIndex++),count));
                count = endIndex - startIndex;
                result = (result > count) ? result : count;
            }
            else {
                temp.erase(s.at(startIndex++));
                count = 0;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;

    cout << solution.lengthOfLongestSubstring("abcdefgh") << endl;
    
    return 0;
}