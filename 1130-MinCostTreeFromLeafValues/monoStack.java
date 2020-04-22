import java.util.LinkedList;

class Solution {
    public int mctFromLeafValues(int[] arr) {
        int len = arr.length;
        if (len <= 1) return 0;

        int res = 0;
        LinkedList<Integer> cache = new LinkedList<>();
        cache.addLast(Integer.MAX_VALUE);
        for (int temp : arr) {
            while (temp > cache.peekLast()) {
                int getLast = cache.pollLast();
                res += Math.min(temp, cache.peekLast()) * getLast;
            }
            cache.addLast(temp);
        }
        while (cache.size() > 2) {
            //Do not forget there is a MAX_VALUE in this List
            res += cache.pollLast() * cache.peekLast();
        }
        return res;
    }
    /* We need to solve the solution like 6,5,4,3,2,1
     * so we need a stack to help us create this monotone situation
     * */
}