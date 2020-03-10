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
        int count = 1;
        char start;
        char now;
        //从前往后字符串遍历
        for(int i = 0 ; i < s.length() - 1 ; i++)
        {
            start = s.at(i);
            //每个字符创一个哈希表
            unordered_map<char, int> temp;
            temp.insert(make_pair(start, count));
            //cout << i << ": " << start << " ";
            //循环边界
            while(i + count < s.length())
            {
                now = s.at(i + count);
                //遍历器
                unordered_map<char, int>::const_iterator got = temp.find(now);
                //之前没有的字符
                if(got == temp.end())
                {
                    count++;
                    temp.insert(make_pair(now, count));
                }
                else
                    break;
            }
            //本次是否更长
            if(count > result)
                result = count;
            //cout << count << endl;

            count = 1;
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