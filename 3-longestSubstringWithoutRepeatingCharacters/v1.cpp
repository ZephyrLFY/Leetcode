#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len < 2) return len;
        int left = 0, right = 0;
        int res = 0;
        unordered_map<char, int> hash(0);
        while(right < len) {
            if(hash.find(s[right]) != hash.end() && hash[s[right]] >= left) {
                res = max(res, right - left);
                left = hash[s[right]] + 1;
            }
            hash[s[right]] = right;
            right++;
        }
        res = max(res, right - left);
        return res;
    }
};

int main()
{
    Solution solu;
    string s;
    cin >> s;
    cout << solu.lengthOfLongestSubstring(s) << endl;
    return 0;
}