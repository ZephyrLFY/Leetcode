class Solution {
    public boolean canJump(int[] nums) {
        int len = nums.length;
        int curEnd = 0, curFurthest = 0; //定位器，Furthest表示可达到的最远距离，End表示目前的目标地点
        for (int i = 0; i < len; i++) {
            curFurthest = Math.max(curFurthest, i + nums[i]);
            if (i == curEnd) {
                curEnd = curFurthest;
                if(i == curFurthest) break; //不能继续往下走了
            }
        }
        return curEnd >= len - 1 ? true : false;
    }

    public static void main(final String[] args) {
        final var nums = new int[] { 2, 5, 0, 0 };
        final var solu = new Solution();
        System.out.println(solu.canJump(nums));
    }
}