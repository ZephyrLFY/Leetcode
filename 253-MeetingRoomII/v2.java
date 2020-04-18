import java.util.Arrays;

class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int len = intervals.length;
        if (len == 0) return 0;

        /* 把开始和结束时间都存起来，并排序
         * 每次遇到一个开始时间，判断是否有一个结束了的房间
         * 如果有，就把这个房间占用，不需要新的房间
         * 没有就开一个新的
         * */
        int[] start = new int[len];
        int[] end = new int[len];
        int res = 0;

        for (int i = 0; i < len; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        Arrays.sort(start);
        Arrays.sort(end);

        for (int i = 0, j = 0; i < len; i++) {
            if (start[i] < end[j]) res++;
            else j++;
        }
            
        return res;
    }
}