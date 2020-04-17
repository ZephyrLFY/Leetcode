import java.lang.reflect.Array;

import java.util.Deque;
import java.util.ArrayDeque;

class Solution {
    public int maximalSquare(char[][] matrix) {
        // Corner Case
        int rows = matrix.length;
        if (rows == 0) return 0;
        int cols = matrix[0].length;

        //DP arrays: leftLessMin, rightLessMin
        //leftLessMin: The largest index of '0' in this row
        //rightLessMin: The smallest index of '0' in this row
        int[] heights = new int[cols];
        int[] leftLessMin = new int[cols];
        int[] rightLessMin = new int[cols];
        Arrays.fill(leftLessMin, -1);
        Arrays.fill(rightLessMin, cols);
        int res = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                //Update heights array for this row
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }

            //Figure leftLessMin for each col
            int boundary = -1;
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') leftLessMin[j] = Math.max(boundary, leftLessMin[j]);
                else {
                    leftLessMin[j] = -1;
                    boundary = j;
                }
            }

            //RightLessMin for each col
            boundary = cols;
            for (int j = cols - 1; j > -1; j--) {
                if (matrix[i][j] == '1') rightLessMin[j] = Math.min(boundary, rightLessMin[j]);
                else {
                    rightLessMin[j] = cols;
                    boundary = j;
                }
            }

            //Like leetcode84, leftMin and rightMin limit the rectangle with heights[col]
            for (int j = 0; j < cols; j++) {
                if (heights[j] <= (rightLessMin[j] - leftLessMin[j] - 1))
                    res = Math.max(res, heights[j] * heights[j]);
            }
        }
        return res;
    }
}