class Solution {
    public boolean canJump(int[] nums) {
        int len = nums.length;
        boolean[] dp = new boolean[len];
        dp[0] = true;
        for(int i = 0; i < len; i++) {
            for(int j = 0; j <= nums[i]; j++) {
                dp[j] = true;
            }
        }
        return dp[len - 1];
    }
    public static void main(String[] args) {
        var nums = new int[] {2,3,1,1,4};
        var solu = new Solution();
        System.out.println(solu.canJump(nums));
    }
}