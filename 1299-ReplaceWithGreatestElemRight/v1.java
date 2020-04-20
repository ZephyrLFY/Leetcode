class Solution {
    //DP Algorithm
    // public int[] replaceElements(int[] arr) {
    //     int len = arr.length;
    //     if (len == 0) return new int[]{};
    //     if (len == 1) return new int[]{-1};
    //     int[] dp = new int[len];
    //     dp[len - 1] = -1;
    //     for (int i = len - 2; i >= 0; i--)
    //         dp[i] = Math.max(dp[i + 1], arr[i + 1]);
    //     return dp;
    // }

    //In Place
    public int[] replaceElements(int[] arr) {
        int len = arr.length;
        if (len == 0) return new int[]{};
        if (len == 1) return new int[]{-1};
        
        int rightMax = -1;
        for (int i = len - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = rightMax;
            if (temp > rightMax) rightMax = temp;
        }
        return arr;
    }
}