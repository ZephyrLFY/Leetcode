class Solution {
    public boolean validMountainArray(int[] A) {
        int len = A.length;
        if (len < 3) return false;
        
        int i = 0, j = len - 1;
        // Two Turn
        while (i < len - 2 && A[i] < A[i + 1]) i++;

        while (j > 1 && A[j] < A[j - 1]) j--;

        return i == j;
        /******************** One Turn
         * boolean left = false, right = false;
         * while (!left || !right) {
         *     if (!left) {
         *         if (A[i] == A[i + 1]) return false;
         *         else if (A[i] < A[i + 1]) {
         *             i++;
         *             if (i == len - 1) break;
         *         }
         *         else left = true;
         *     }
         *     else {
         *         if (A[j] == A[j - 1]) return false;
         *         else if (A[j] < A[j - 1]) {
         *             j--;
         *             if (j == 0) break;
         *         }
         *         else right = true;
         *     }
         * }
         * if (i == j && i != 0 && j != len - 1) return true;
         * return false;
         */
    }
}