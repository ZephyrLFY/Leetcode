class Solution {
    public int[] sortedSquares(int[] A) {
        int len = A.length;
        int i = 0, j = len - 1;
        //From the start and end, which can solve the negative numbers in the front
        int[] res = new int[len];
        for (int k = len - 1; k >= 0; k--) {
            int sq1 = A[i] * A[i];
            int sq2 = A[j] * A[j];
            if (sq1 < sq2) {
                res[k] = sq2;
                j--;
            }
            else {
                res[k] = sq1;
                i++;
            }
        }
        return res;
    }
}