class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int len = nums.length;
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        
        int res = 0;
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == 1) count++;
            else {
                res = Math.max(res, count);
                count = 0;
            }
        }
        res = Math.max(res, count);
        return res;
    }
}