#include "../cppLib.h"
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> seen1;
        unordered_set<string> seen2;
        queue<string> stack1;
        queue<string> stack2;
        unordered_set<string> wordSet(wordList.begin(), wordList.end(), wordList.size());
        if (!wordSet.count(endWord)) return 0;
        stack1.push(beginWord);
        stack2.push(endWord);
        seen1.insert(beginWord);
        seen2.insert(endWord);
        int step = 0;
        while (!stack1.empty() && !stack2.empty()) {
            if (stack1.size() > stack2.size()) {
                stack1.swap(stack2);
                seen1.swap(seen2);
            }
            int size = stack1.size();
            step++;
            for (int i = 0; i < size; i++) {
                string cur(stack1.front());
                stack1.pop();
                for (int j = 0; j < cur.size(); j++) {
                    char temp = cur[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        cur[j] = c;
                        if (seen1.count(cur)) continue;
                        if (seen2.count(cur)) return step + 1;
                        if (wordSet.count(cur)) {
                            stack1.push(cur);
                            seen1.insert(cur);
                        }
                    }
                    cur[j] = temp;
                }
            }
        }
        return 0;
    }
};