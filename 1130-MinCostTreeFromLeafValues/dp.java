class Solution {
    public int mctFromLeafValues(int[] arr) {
        int len = arr.length;
        int[][] dp = new int[len][len];
        int[][] maxVal = new int[len][len];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int max = 0;
                for (int k = i; k <= j; k++) if (max < arr[k]) max = arr[k];
                maxVal[i][j] = max;
            }
        }
        for (int i = 0; i < len; i++) for (int j = 0; j < len; j++) dp[i][j] = Integer.MAX_VALUE;
        for (int i = 0; i < len; i++) dp[i][i] = 0;
        for (int i = 1; i < len; i++) { // 长度
            for (int j = 0; j < len - i; j++) { // 起始点
                for (int k = j; k < j + i; k++) { // 中间点
                    dp[j][j+i] = Math.min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + maxVal[j][k] * maxVal[k+1][j+i]);
                }
            }
        }
        return dp[0][len-1];
    }
    //Do a DP, where dp(i, j) is the answer for the subarray arr[i]..arr[j].
    //For each possible way to partition the subarray i <= k < j, 
    //the answer is max(arr[i]..arr[k]) * max(arr[k+1]..arr[j]) + dp(i, k) + dp(k+1, j).
}