class Solution {
    public int removeElement(int[] nums, int val) {
        int begin = 0; //Record how many numbers are not equal to val
        for (int temp : nums)
            if (temp != val)
                nums[begin++] = temp;
                //begin++ : The next position of number which not equals val should be placed
        
        return begin;
    }
}