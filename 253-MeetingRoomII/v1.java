import java.util.PriorityQueue;
import java.util.Arrays;

class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int len = intervals.length;
        if (len == 0) return 0;

        //Min Heap
        PriorityQueue<Integer> heap = new PriorityQueue<>(len);

        //Override the compare method for int[]
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(final int[] a, final int[] b) {
                return a[0] - b[0];
            }
        });

        //Add the first
        heap.add(intervals[0][1]);

        for (int i = 0; i < len; i++) {
            if (intervals[i][0] >= heap.peek()) heap.poll(); //Recycle the first-over room
            heap.add(intervals[i][1]);
        }

        return heap.size();
    }
}