class Solution {
    public int findNumbers(int[] nums) {
        int len = nums.length;
        if (len == 0) return 0;
        
        int res = 0;
        int count = 0;
        
        for (int i = 0; i < len; i++) {
            int temp = nums[i] / 10;
            while(temp != 0) {
                count++;
                temp = temp / 10;
            }
            count++;
            if (count % 2 == 0) res++;
            count = 0;
        }
        return res;
    }
}