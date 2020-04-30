class Solution {
    public int climbStairs(int n) {
        if (n == 1) return 1;
        int prer = 1;
        int pre = 2;
        int temp;
        for (int i = 2; i < n; i++) {
            temp = pre;
            pre += prer;
            prer = temp;
        }
        return pre;
    }
}