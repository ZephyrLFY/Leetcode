import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

class Solution {
    private Set<String> res = new HashSet<String>();

    public List<String> removeInvalidParentheses(String s) {
        String temp = "";
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            char cur = s.charAt(i);
            if (cur == '(') left++;
            else if (cur == ')') {
                if (left > 0) left--;
                else right++;
            }
        }
        dfs(s, 0, 0, 0, temp, left, right);
        return new ArrayList<String>(res);
    }

    /* DFS
     * temp: 目前已得到的String，index表示接下来该分析的位置
     * left/rightCount: num of '(' or ')' in temp
     * count: How many removes have been done
     * 可行结果：leftCount == rightCount, and reach the end of s
     * if count > minRemove, 本次的遍历无效，清空
     * */
    public void dfs(String s, int index, int leftCount, int rightCount, 
        String temp, int leftRes, int rightRes) {
        if (index == s.length()) {
            if (leftRes == 0 && rightRes == 0) res.add(temp);
            return;
        }

        if (s.charAt(index) == '(') {
            dfs(s, index + 1, leftCount, rightCount, temp, leftRes - 1, rightRes);
            dfs(s, index + 1, leftCount + 1, rightCount, temp + "(", leftRes, rightRes);
        }
        else if (s.charAt(index) == ')') {
            dfs(s, index + 1, leftCount, rightCount, temp, leftRes, rightRes - 1);
            //If rightCount >= leftCount, then cannot add ')', otherwise temp will be invalid
            if (rightCount < leftCount)
                dfs(s, index + 1, leftCount, rightCount + 1, temp + ")", leftRes, rightRes);
        }
        else {
            String mid = temp + String.valueOf(s.charAt(index));
            dfs(s, index + 1, leftCount, rightCount, mid, leftRes, rightRes);
        }
    }
}