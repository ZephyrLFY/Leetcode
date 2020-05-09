class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len <= 1) return len;

        int res = 0, i = 0, j = 0;
        while (j < len) {
            //j points to next different num
            if (nums[i] == nums[j]) {
                j++;
                continue;
            }

            nums[++i] = nums[j++];
            res++;
        }
        return res + 1; //The first num didn't add res yet
    }
}