class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int len = nums.length;
        //Corner Case
        if (len <= 1) return len;

        int[] prefix = new int[len];
        int[] suffix = new int[len];
        int res = 0;

        /* 预处理 + 枚举
         * 从某个0开始，左边连续的1和右边连续的1可以被这个0改成1而连起来
         * 所以prefix[i]和suffix[i]分别存以i结尾和开头的子序列结尾和开头的连续1的个数
         * */
        prefix[0] = (nums[0] == 1) ? 1 : 0;
        for (int i = 1; i < len; i++) {
            prefix[i] = (nums[i] == 1) ? prefix[i - 1] + 1 : 0;
            res = Math.max(res, prefix[i]);
        }

        suffix[len - 1] = (nums[len - 1] == 1) ? 1 : 0;
        for (int j = len - 2; j >= 0; j--)
            suffix[j] = (nums[j] == 1) ? suffix[j + 1] + 1 : 0;

        for (int k = 0; k < len; k++) {
            //For each zero
            if (nums[k] == 0) {
                int temp = 0;
                if (k > 0) temp += prefix[k - 1];
                if (k < len - 1) temp += suffix[k + 1];
                res = Math.max(res, temp + 1);
            }
        }
        
        return res;
    }
}