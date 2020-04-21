class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int res = 0, count = 0;

        /* 题目等价于：求只能包含一个0的区间最大长度
         * 所以滑动窗口：遇到第二个0，则左移边界直到把第一个0去掉
         * */
        for(int l = 0, r = 0; r < nums.length; r++) {
            if(nums[r] == 0) {
                count++;
                while(count > 1) {
                    count -= nums[l++] == 0 ? 1 : 0;
                }
            }
            res = Math.max(res, r - l + 1);
        }

        return res;
    }
}