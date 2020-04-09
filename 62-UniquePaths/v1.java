class Solution {
    private int paths = 0;
    public int uniquePaths(int m, int n) {
        int right = m - 1, down = n - 1;
        findPath(right, down);
        return paths;
    }

    public void findPath(int right, int down) {
        if (right == 0 && down == 0) {
            paths++;
            return;
        }
        if (right > 0) findPath(right - 1, down);
        if (down > 0) findPath(right, down - 1);
    }

    public static void main(String[] args) {
        var test = new Solution();
        System.out.println(test.uniquePaths(51, 9));
    }
}