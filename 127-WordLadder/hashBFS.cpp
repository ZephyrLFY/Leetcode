#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = beginWord.size();
        vector<unordered_map<string, vector<string>>> lib(len);
        unordered_set<string> seen;
        queue<string> stack;
        for (int i = 0; i < len; i++) {
            for (string cur : wordList) {
                string temp = cur;
                temp.erase(i, 1);
                lib[i][temp].push_back(cur);
            }
        }
        stack.push(beginWord);
        int step = 0;
        while (!stack.empty()) {
            int size = stack.size();
            step++;
            for (int i = 0; i < size; i++) {
                string cur = stack.front();
                stack.pop();
                if (cur == endWord) return step;
                if (seen.count(cur)) continue;
                seen.insert(cur);
                for (int j = 0; j < len; j++) {
                    string temp = cur;
                    temp.erase(j, 1);
                    if (lib[j].count(temp)) {
                        for (string origin : lib[j][temp])
                            if (!seen.count(origin)) stack.push(origin);
                    }
                }
            }
        }
        return 0;
    }
};