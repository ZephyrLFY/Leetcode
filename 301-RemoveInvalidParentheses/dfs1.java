import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

class Solution {
    private Set<String> res = new HashSet<String>();
    private int minRemove = Integer.MAX_VALUE;

    public List<String> removeInvalidParentheses(String s) {
        String temp = "";
        dfs(s, 0, 0, 0, temp, 0);
        return new ArrayList<String>(res);
    }

    /* DFS
     * temp: 目前已得到的String，index表示接下来该分析的位置
     * left/rightCount: num of '(' or ')' in temp
     * count: How many removes have been done
     * 可行结果：leftCount == rightCount, and reach the end of s
     * if count > minRemove, 本次的遍历无效，清空
     * */
    public void dfs(String s, int index, int leftCount, int rightCount, String temp, int count) {
        if (index == s.length()) {
            if (leftCount == rightCount) {
                if (count <= minRemove) {
                    if (count < minRemove) res.clear();
                    res.add(temp);
                    minRemove = count;
                }
            }
            return;
        }

        if (s.charAt(index) == '(') {
            dfs(s, index + 1, leftCount, rightCount, temp, count + 1);
            dfs(s, index + 1, leftCount + 1, rightCount, temp + "(", count);
        }
        else if (s.charAt(index) == ')') {
            dfs(s, index + 1, leftCount, rightCount, temp, count + 1);
            //If rightCount >= leftCount, then cannot add ')', otherwise temp will be invalid
            if (rightCount < leftCount)
                dfs(s, index + 1, leftCount, rightCount + 1, temp + ")", count);
        }
        else {
            String mid = temp + String.valueOf(s.charAt(index));
            dfs(s, index + 1, leftCount, rightCount, mid, count);
        }
    }
}