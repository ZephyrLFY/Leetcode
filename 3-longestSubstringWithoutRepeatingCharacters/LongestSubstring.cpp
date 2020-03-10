#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        int result = 1;
        int count = 1;
        char start;
        for(int i = 0 ; i < s.length() - 1 ; i++)
        {
            start = s.at(i);
            cout << i << ": " << start << " ";

            while(s.at(i + count) != start && i < s.length() - 1)
            {
                count++;
                if(i + count == s.length())
                    break;
            }

            if(count > result)
                result = count;
            cout << count << endl;

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