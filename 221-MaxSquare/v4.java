class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length;
        if (rows == 0) return 0;
        int cols = matrix[0].length;

        //dp[i][j]: 以(i, j)为右下角的正方形的最大边长
        //后续可以进一步压缩为两个dp[] + 一个左上角的记录值northWestern
        int[][] dp = new int[rows][cols];
        int max = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else
                        dp[i][j] = Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    //上面这一步是关键，通过三者的最小值刻画出能否形成新的正方形
                    max = Math.max(max, dp[i][j]);
                }
            }
        }
        return max * max;
    }
}