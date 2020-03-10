#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //傻逼输入处理
        if(s.length() == 0)
            return 0;

        int result = 1;
        int count = 0;
        char now;

        //滑动窗口的开始与结束
        int startIndex = 0;
        int endIndex = 0;

        //从前往后字符串遍历
        for(startIndex = 0 ; startIndex < s.length() - 1 ; startIndex++) 
        {
            //cout << "Start from: " << s.at(startIndex) << endl;
            unordered_map<char, int> temp;
            unordered_map<char, int>::const_iterator got;
            for(endIndex = startIndex ; endIndex < s.length() ; endIndex++)
            {
                now = s.at(endIndex);
                got = temp.find(now);
                if(got == temp.end()) {
                    temp.insert(make_pair(now,count));
                    //cout << "insert:" << now << endl;
                    count++;
                }
                else {
                    break;
                }
            }
            if(result < count) {
                result = count;
            }
            //cout << s.at(startIndex) << "'s turn is over, and it's result is: " << count << endl;
            count = 0;
        }
        return result;
    }
};

int main()
{
    Solution solution;

    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
    
    return 0;
}