class Solution {
    private int[][] dp;

    public int cal(int m, int n) {
        if (m == 1 || n == 1) return 1;
        else if (m == 2) return n;
        else if (n == 2) return m;
        if (dp[m][n] > 0) return dp[m][n];
        dp[m - 1][n] = cal(m - 1, n);
        dp[n][m - 1] = dp[m - 1][n];
        dp[m][n - 1] = cal(m, n - 1);
        dp[n - 1][m] = dp[m][n - 1];
        dp[m][n] = dp[m - 1][n] + dp[m][n - 1];
        return dp[m][n];
    }

    public int uniquePaths(int m, int n) {
        int bigger = Math.max(m, n) + 1;
        dp = new int[bigger][bigger];
        return cal(m, n);
    }

    public static void main(String[] args) {
        var solu = new Solution();
        System.out.println(solu.uniquePaths(7, 3));
    }
}