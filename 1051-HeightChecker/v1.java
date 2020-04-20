class Solution {
    public int heightChecker(int[] heights) {
        int len = heights.length;
        if (len <= 1) return 0;
        
        // 遍历数组heights，计算每个桶中有多少个元素，也就是数组heights中有多少个1，多少个2 ... 多少个100
        // 将这101个桶中的元素，一个一个桶地取出来，元素就是有序的
        int[] arr = new int[101];
        for (int height : heights)
            arr[height]++;

        int count = 0;
        for (int i = 1, j = 0; i < 101; i++) {
            // i就是桶中存放的元素的值，arr[i]是元素的个数
            while (arr[i] > 0) {
                //While this bucket is not empty
                if (heights[j++] != i) count++;
                arr[i]--;
            }
        }
        return count;
    }
}