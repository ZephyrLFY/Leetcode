#include "../cppLib.h"

class Solution {
private:
    unordered_map<string, int> map;
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        for (string temp : banned) ban.insert(temp);
        int times = 0;
        string res;
        paragraph += ' ';
        int len = paragraph.size();
        int i = 0, j = 0;
        while (j < len) {
            char cur = paragraph[j];
            if (isalpha(cur)) {
                if (isupper(cur)) paragraph[j] += 32;
                j++;
            }
            else {
                string temp = paragraph.substr(i, j - i);
                if (!ban.count(temp)) {
                    map[temp]++;
                    if (map[temp] > times) {
                        times = map[temp];
                        res = temp;
                    }
                }
                while (j < len && !isalpha(paragraph[j])) j++;
                i = j;
            }
        }
        return res;
    }
};