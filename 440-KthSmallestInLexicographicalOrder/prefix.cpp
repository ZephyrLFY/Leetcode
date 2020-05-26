#include <iostream>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        //cur是第几个数，prefix是前缀
        int cur = 1, prefix = 1; //从1开始
        while (cur < k) {
            int temp = count(n, prefix); //计算该结点有几个后缀结点
            if (cur + temp > k) { //在该节点内部，位数加1
                prefix *= 10;
                ++cur;
            }
            else { //仍未到目标k，前缀进行加法调整
                ++prefix;
                cur += temp;
            }
        }
        return prefix;
    }

    int count (int n, int prefix) {
        long cur = prefix; //开始扫描的前缀
        long next = cur + 1; //下一次的前缀
        int count = 0; //一共跳过了多少个结点
        while (cur <= n) {
            count += (n + 1 <= next ? n + 1 : next) - cur; //该前缀对应的后继有多少
            cur *= 10;
            next *= 10;
        }
        return count;
    }
};