class Solution {
    public void moveZeroes(int[] nums) {
        int len = nums.length;
        if (len <= 1) return;
        
        int cur = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) continue;
            else {
                if (i != cur) { //Self do not need to swap
                    nums[cur] = nums[i];
                    nums[i] = 0;
                }
                cur++;
            }
        }
    }
}