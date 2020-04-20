import java.util.Set;
import java.util.HashSet;

class Solution {
    public boolean checkIfExist(int[] arr) {
        int len = arr.length;
        if (len <= 1) return false;
        Set<Integer> cache = new HashSet<>();
        for (int i = 0; i < len; i++) {
            int temp = arr[i];
            if (cache.contains(temp)) return true;
            else if (temp % 2 == 0) cache.add(temp / 2);
            cache.add(temp * 2);
        }
        return false;
    }
}