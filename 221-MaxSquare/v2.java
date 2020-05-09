class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length;
        if (rows == 0) return 0;
        int cols = matrix[0].length;

        int[] heights = new int[cols];
        int res = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) { //For each row, deal heights[]
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }

            res = Math.max(res, largestSquareArea(heights));
        }
        return res;
    }

    public int largestSquareArea(int[] heights) {
        int len = heights.length;
        if (len == 0) return 0;
        if (len == 1) return 1;

        //新建一个数组，两端设置哨兵0
        len += 2;
        int[] newHeights = new int[len];
        System.arraycopy(heights, 0, newHeights, 1, len - 2);
        heights = newHeights;
        heights[0] = 0;
        heights[len - 1] = 0;

        //单调栈，每次遇到小于前一个数的数时，出栈算面积
        int res = 0;
        var stack = new ArrayDeque<Integer>(len);
        stack.add(0);
        for (int i = 1; i < len; i++) {
            while (heights[i] < heights[stack.peekLast()]) {
                int curHeight = heights[stack.removeLast()];
                /*这一步中的宽度计算是精髓
                * 即对于每一个高度
                * 计算一次由两端卡住的最大面积*/
                if (curHeight <= (i - stack.peekLast() - 1))
                    res = Math.max(res, curHeight * curHeight);
            }
            stack.addLast(i);
        }
        return res;
    }
}