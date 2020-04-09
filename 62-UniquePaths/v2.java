import java.math.BigInteger;

class Solution {
    public int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        if (m < n) {
            int temp = m;
            m = n;
            n = temp;
        }

        var res = new BigInteger("1");
        var divide = new BigInteger("1");
        for (int i = m; i <= m + n - 2; i++) res = res.multiply(BigInteger.valueOf(i));
        for (int i = 2; i <= n - 1; i++) divide = divide.multiply(BigInteger.valueOf(i));
        return res.divide(divide).intValue();
    }
}