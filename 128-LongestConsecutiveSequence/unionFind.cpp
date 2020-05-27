#include "../cppLib.h"

class Solution {
private:
    unordered_map<int, int> uf, cnt;
public:
    int find(int i) {
        if (i == uf[i]) return i;
        else uf[i] = find(uf[i]);
        return uf[i];
    }

    int merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return cnt[x];
        uf[y] = x;
        cnt[x] += cnt[y];
        return cnt[x];
    }

    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if (!len) return 0;
        for (int num : nums) {
            uf[num] = num;
            cnt[num] = 1;
        }
        int res = 1;
        for (int num : nums) {
            if (num != INT_MAX && uf.count(num + 1)) res = max(res, merge(num, num + 1));
        }
        return res;
    }
};