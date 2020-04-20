class Solution {
    public void moveZeroes(int[] nums) {
        int len = nums.length;
        if (len <= 1) return;
        int cur = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) continue;
            else {
                int temp = nums[cur];
                nums[cur++] = nums[i];
                nums[i] = temp;
            }
        }
    }
}