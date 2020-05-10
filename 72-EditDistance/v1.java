import java.util.Arrays;

class Solution {
    public int minDistance(String word1, String word2) {
        char[] word1Array = word1.toCharArray();
        char[] word2Array = word2.toCharArray();
        int num1 = word1Array.length;
        int num2 = word2Array.length;
        var dp = new int[num1 + 1][num2 + 1]; //多初始化了一行一列，防止word1或者word2为空
        //初始化Corner Case
        dp[0][0] = 0;
        for (int i = 1; i < num1 + 1; i++) dp[i][0] = i;
        for (int j = 1; j < num2 + 1; j++) dp[0][j] = j;
        
        for (int i = 1; i < num1 + 1; i++)
            for (int j = 1; j < num2 + 1; j++) {
                //一定要注意这里的word1[i - 1] and word2[j - 1]中的减一，因为多出来的一行一列都在最开头而不是末尾
                if (word1Array[i - 1] == word2Array[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
            }
        return dp[num1][num2];
    }
}