class Solution {
    private int[][] dp;

    public int minPathSum(int[][] grid) {
        int lines = grid.length, rows = grid[0].length;
        dp = new int[lines][rows];
        dp[0][0] = grid[0][0]; //初始化左上角
        for (int i = 0; i < lines; i++)
            for (int j = 0; j < rows; j++) {
                if (i ==0 && j == 0) continue; //跳过左上角
                else if (i == 0) dp[i][j] = dp[i][j - 1] + grid[i][j]; //第一行
                else if (j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j]; //第一列
                else dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]; //正常情况
            }
        return dp[lines - 1][rows - 1];
    }

    public static void main(String[] args) {
        var solu = new Solution();
        var grid = new int[][] {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
        System.out.println(solu.minPathSum(grid));
    }
}