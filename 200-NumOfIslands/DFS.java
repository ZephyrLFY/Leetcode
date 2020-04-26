class Solution {
    //DFS深度优先遍历（类似于探战争迷雾）

    private int rows, cols;

    public int numIslands(char[][] grid) {
        rows = grid.length;
        if (rows == 0) return 0;
        cols = grid[0].length;
        int nums = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    //发现一个1，即从这一点开始展开
                    nums++;
                    dfs(grid, i, j);
                }
            }
        return nums;
    }
    
    public void dfs(char[][] grid, int row, int col) {
        grid[row][col] = '0'; //改为0表示这一点已经探索过
        if (row > 0 && grid[row - 1][col] == '1') dfs(grid, row - 1, col);
        if (row < rows - 1 && grid[row + 1][col] == '1') dfs(grid, row + 1, col);
        if (col > 0 && grid[row][col - 1] == '1') dfs(grid, row, col - 1);
        if (col < cols - 1 && grid[row][col + 1] == '1') dfs(grid, row, col + 1);
    }
}