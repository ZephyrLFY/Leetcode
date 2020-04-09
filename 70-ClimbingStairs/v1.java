import java.util.*;

class Solution {
    private int ways = 0;

    public int climbStairs(int n) {
        nextStep(n);
        return ways;
    }

    public void nextStep(int n) {
        if (n == 0) {
            ways++;
            return;
        }
        if (n > 1) nextStep(n - 2);
        nextStep(n - 1);
    }

    public static void main(String[] args) {
        var solu = new Solution();
        Scanner nums = new Scanner(System.in);
        int num = nums.nextInt();
        System.out.println(solu.climbStairs(num));
    }
}