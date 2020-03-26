#include <iostream>
#include <vector>
using namespace std;

int memo[50000];
class Solution {
public:
    int jump(vector<int>& nums) {
        int count = nums.size();
        if(!count) return 0; //只有一个数，结果为0
        int last = 0; //上一次能到达的最远距离
        memset(memo, 0, count*sizeof(int));
        for(int i = 0; i < count - 1; i++) {
            int steps = memo[i] + 1;
            int j = i + nums[i]; //能到达的最远距离
            if(j >= count - 1) return steps; //能一步跳到结尾
            if(j <= last) continue; //不如上次能到的距离远
            for(int k = j; k > last; k--) memo[k] = steps; 
            last = j; //更新最远距离
        }
        return 0;
    }
};