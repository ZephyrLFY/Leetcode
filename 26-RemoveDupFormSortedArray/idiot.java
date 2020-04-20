import java.util.Set;
import java.util.HashSet;

class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len <= 1) return len;
        int cur = 0, i = 0;
        Set<Integer> cache = new HashSet<>();
        while (i < len) {
            if (cache.contains(nums[i])) {
                i++;
                continue;
            }

            if (cache.contains(nums[cur]))
                nums[cur] = nums[i];
            cache.add(nums[cur++]);
        }
        return cache.size();
    }
}