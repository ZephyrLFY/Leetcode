class Solution {
    public int thirdMax(int[] nums) {
        //这道题的flag折磨死我了
        
        int len = nums.length;
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return nums[0] > nums[1] ? nums[0] : nums[1];

        int first = 0x80000000, second = first, third = first;
        boolean flag1 = false, flag2 = false, flag3 = false;
        for (int temp : nums) {
            if (temp >= first) {
                if (flag1 && temp != first) {
                    if (flag2) {
                        third = second;
                        flag3 = true;
                    }
                    second = first;
                    flag2 = true;
                }
                first = temp;
                flag1 = true;
            }
            else if (temp >= second && temp != first) {
                if (flag2 && temp != second) {
                    third = second;
                    flag3 = true;
                }
                second = temp;
                flag2 = true;
            }
            else if (temp >= third && temp != first && temp != second) {
                third = temp;
                flag3 = true;
            }
        }
        return flag3 ? third : first;
    }
}