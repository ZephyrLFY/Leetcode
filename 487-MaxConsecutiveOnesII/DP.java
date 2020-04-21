class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int len = nums.length;
        //Corner Case
        if (len <= 1) return len;

        int dp0 = 0, dp1 = 0;
        //dp0:前一个位置为结尾的，还没有改过0的最长连续1
        //dp1:前一个位置为结尾，改过的情况下最长连续1
        //注意：dp0和dp1只有在结尾是1的时候才是正确的数字，但不影响最终结果，因为每次都会求max
        int res = 0;

        /* For dp0: if nums[i] == 0, dp0 = 0; else, dp0 = dp0 + 1
         * For dp1: if nums[i] == 0, dp1 = dp0 + 1; else dp1 = dp1 + 1
         * */
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
                dp1 = dp0 + 1;
                dp0 = 0;
            }
            else {
                dp0++;
                dp1++;
            }
            res = Math.max(Math.max(dp0, dp1), res);
        }
        
        return res;
    }
}