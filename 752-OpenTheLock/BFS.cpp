#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public: 
    int openLock(vector<string>& deadends, string target) {
        const string start = "0000";
        int step = 0;
        queue<string> queue;
        unordered_set<string> visited;
        unordered_set<string> dead;
        for (string s : deadends) {
            dead.insert(s);
        }
        queue.push(start);
        while (!queue.empty()) {
            ++step;
            int size = queue.size(); //本轮需要处理的个数
            for (int i = 0; i < size; i++) {
                const string cur = queue.front();
                queue.pop();
                for (int j = 0; j < 4; j++) { //改变每一位
                    for (int k = -1; k <= 1; k += 2) { //加一或减一
                        string temp = cur;
                        temp[j] = (temp[j] -'0' + k + 10) % 10 + '0';
                        if (temp == target) return step;
                        if (dead.count(temp) || visited.count(temp)) continue;
                        queue.push(temp);
                        visited.insert(temp);
                    }
                }
            }
        }
        return -1;
    }
};