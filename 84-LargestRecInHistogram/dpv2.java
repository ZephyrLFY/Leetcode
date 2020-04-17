class Solution {
    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
        if (len == 0) return 0;
        if (len == 1) return heights[0];
        int[] dp = new int[len];
        int res = 0;
        for (int i = 0; i < len; i++)
            for (int j = i; j < len; j++) { //只需要考虑上半部分
                if (i == j) dp[j] = heights[i]; //一格
                else dp[j] = Math.min(dp[j - 1], heights[j]); //选取最矮的（木桶效应）
                res = Math.max(res, dp[j] * (j - i + 1));
            }
        return res;
    }
}