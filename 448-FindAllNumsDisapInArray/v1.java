import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int len = nums.length;
        List<Integer> res = new ArrayList<>();
        if (len == 0) return res;
        for (int i = 0; i < len; i++) {
            while (nums[nums[i] - 1] != nums[i]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] != i + 1) res.add(i + 1);
        }
        return res;
    }

    public static void main(String[] args) {
        var solu = new Solution();
        int[] nums = {4,3,2,7,8,2,3,1};
        var res = solu.findDisappearedNumbers(nums);
        for (int temp : res) {
            System.out.print(temp + "\t");
        }
    }
}