#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> bucket(26, 0);
        for (char c : tasks) {
            bucket[c - 'A']++;
        }
        sort(bucket.begin(), bucket.end());
        int res = 0;
        while (bucket[25] > 0) {
            //桶排序，每一轮最多选n + 1个，会使每一轮每个任务最多执行一次
            int i = 0;
            while (i <= n) {
                if (bucket[25] == 0) break;
                if (i < 26 && bucket[25 - i])
                    bucket[25 - i]--;
                res++;
                i++;
            }
            sort(bucket.begin(), bucket.end());
        }
        return res;
    }
};