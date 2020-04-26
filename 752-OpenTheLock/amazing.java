import java.util.List;

class Solution {
      public int openLock(String[] deadends, String target) {
        final List<String> deals = Arrays.asList(deadends);
        if (deals.contains("0000")) return -1;

        final List<String> options = new ArrayList<>(); // 可达目标数的 8 个状态
        for (int i = 0; i < 4; i++) {
            char[] cs = target.toCharArray();
            char c = cs[i];
            cs[i] = (char) ((c - 48 + 1) % 10 + 48);
            options.add(new String(cs));
            cs[i] = (char) ((c - 48 + 9) % 10 + 48);
            options.add(new String(cs));
        }

        options.removeAll(deals); // 可达数字中移除死亡数字
        if (options.isEmpty()) return -1; // 可达目标数的 8 个状态都在死亡数字中直接返回

        int step = Integer.MAX_VALUE;
        for (String option : options) { // 判断可达状态中最短转动次数
            int curStep = 1;
            char[] cs = option.toCharArray();
            for (int i = 0; i < 4; i++) {
                int num = cs[i] - 48; // '0' 为 48 减少隐式转换
                if (num > 5) curStep += 10 - num; // 判断正转，倒转
                else curStep += num;
            }
            step = Math.min(curStep, step); // 记录最小旋转次数
        }
        return step;
    }
}