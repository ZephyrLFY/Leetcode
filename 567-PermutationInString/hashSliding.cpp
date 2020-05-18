#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char, int> map;
    unordered_map<char, int> del;
public:
    bool checkInclusion(string s1, string s2) {
        for (char c : s1) ++map[c];
        int len1 = s1.size(), len2 = s2.size();
        if (len1 <= 0 || len2 <= 0 || (len1 > len2)) return false;
        int i = 0, j = 0;
        while (j < len2) {
            char cur = s2[j];
            if (map.count(cur)) {
                ++del[cur];
                --map[cur];
                if (!map[cur]) map.erase(cur);
                ++j;
            }
            else {
                if (j - i == len1) return true;
                while (i <= j) {
                    char temp = s2[i];
                    if (del.count(temp)) {
                        --del[temp];
                        if (!del[temp]) del.erase(temp);
                        ++map[temp];
                    }
                    ++i;
                    if (temp == cur) break;
                }
                if (j < i) j = i;
            }
        }
        return map.empty();
    }
};