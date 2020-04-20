class Solution {
    public int[] sortArrayByParity(int[] A) {
        int len = A.length;
        if (len <= 1) return A;

        int i = 0, j = len - 1;
        while (i < j) {
            int left = A[i], right = A[j];
            if (left % 2 != 0 && right % 2 == 0) {
                A[i++] = right;
                A[j--] = left;
            }
            else if (left % 2 == 0) i++;
            else j--;
        }
        return A;
    }
}