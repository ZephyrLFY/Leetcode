class MyComarator implements Comparator<int[]> {
	@Override
	public int compare(int[] o1, int[] o2) {
        if (o1[0]==o2[0]) return o1[1]-o2[1];
        return o1[0]-o2[0];
    }
};
class Solution {
    public int[][] merge(int[][] intervals) {
        final int len = intervals.length;
        if (len <= 1) return intervals; //特判
        int scan = 1, save = 0;
        var list = new ArrayList<int[]>(); //存放结果的ArrayList
        Comparator<int[]> cmp = new MyComarator(); //为了使用重载的compare函数
        Arrays.sort(intervals, 0, len, cmp);
        while (scan < intervals.length) {
            if (intervals[scan][0] > intervals[save][1]) { //No overlaps
                list.add(intervals[save]);
                save = scan;
            }
            else if (intervals[scan][1] <= intervals[save][1]) scan++; //Contain
            else { //Extend
                intervals[save][1] = intervals[scan][1];
                scan++;
            }
        }
        list.add(intervals[save]);
        int[][] res = new int[list.size()][2]; //转化为二维数组输出
        for (int i = 0; i < list.size(); i++) res[i] = list.get(i);
        return res;
    }
}