import java.util.Queue;
import java.util.Set;

class Solution {
    public int openLock(String[] deadends, String target) {
int step = 0;
        Queue<String> queue = new ArrayDeque<>();
        Set<String> visited = new HashSet<>();
        Set<String> dead = new HashSet<>();
        for (String s : deadends) {
            dead.add(s);
        }
        queue.add("0000");
        visited.add("0000");
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String tmp = queue.poll();
                if (dead.contains(tmp)) {
                    continue;
                }
                if (tmp.equals(target)) {
                    return step;
                }
                for (int j = 0; j < 4; j++) {
                    String up = plusOne(tmp, j);
                    if (!visited.contains(up)) {
                        queue.add(up);
                        visited.add(up);
                    }
                    String down = minusOne(tmp, j);
                    if (!visited.contains(down)) {
                        queue.add(down);
                        visited.add(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
    private String minusOne(String tmp, int j) {
        char[] ch = tmp.toCharArray();
        if (ch[j] == '0') {
            ch[j] = '9';
        } else {
            ch[j] -= 1;
        }
        return new String(ch);
    }

    private String plusOne(String tmp, int j) {
        char[] ch = tmp.toCharArray();
        if (ch[j] == '9') {
            ch[j] = '0';
        } else {
            ch[j] += 1;
        }
        return new String(ch);
    }
}