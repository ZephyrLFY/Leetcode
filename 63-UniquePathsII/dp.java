class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int rows = obstacleGrid.length;
        if (rows == 0) return 0;
        int cols = obstacleGrid[0].length;
        
        int[][] dp = new int[rows][cols];
        boolean reach = true;
        for (int i = 0; i < rows; i++) {
            if (obstacleGrid[i][0] == 1) reach = false;
            dp[i][0] = reach ? 1 : 0;
        }
        reach = true;
        for (int j = 0; j < cols; j++) {
            if (obstacleGrid[0][j] == 1) reach = false;
            dp[0][j] = reach ? 1 : 0;
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[rows-1][cols-1];
    }
}