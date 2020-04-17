class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length;
        if (rows == 0) return 0;
        int cols = matrix[0].length;

        int[] heights = new int[cols];
        int dp = 0;
        int res = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) { //For each row, deal heights[]
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }

            //DP, dp = for [m, n], the min heights.
            for (int m = 0; m < cols; m++)
                for (int n = m; n < cols; n++) {
                    if (m = n) dp = heights[m];
                    dp = Math.min(dp, heights[n]);
                    //if [m, n] is a square, figure its area.
                    if (dp == (n - m + 1)) res = Math.max(res, dp * (n - m + 1));
                }
        }
        return res;
    }
}