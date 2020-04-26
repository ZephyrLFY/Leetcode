import java.util.LinkedList;

class Solution {
    //BFS广度优先，需要借助辅助队列

    private int rows, cols;
    private LinkedList<Integer> queue;

    public int numIslands(char[][] grid) {
        rows = grid.length;
        if (rows == 0) return 0;
        cols = grid[0].length;
        int nums = 0;
        queue = new LinkedList<Integer>();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    //发现陆地，开始广度遍历
                    nums++;
                    bfs(grid, i, j);
                    while (!queue.isEmpty()) { //对当前这片陆地的队列处理完
                        int temp = queue.removeFirst();
                        int x = temp / cols;
                        int y = temp % cols;
                        bfs (grid, x, y);
                    }

                }
            }
        return nums;
    }

    public void bfs(char[][] grid, int row, int col) {
        grid[row][col] = '0'; //改为0表示这一点已经探索过（一定要先标记）
        
        //加入队列时处理一下数据，将二维压缩成一维，否则得自己写一个Pair类
        if (row > 0 && grid[row - 1][col] == '1') queue.addLast((row - 1) * cols + col);
        if (row < rows - 1 && grid[row + 1][col] == '1') queue.addLast((row + 1) * cols + col);
        if (col > 0 && grid[row][col - 1] == '1') queue.addLast(row * cols + (col - 1));
        if (col < cols - 1 && grid[row][col + 1] == '1') queue.addLast(row * cols + (col + 1));
    }
}