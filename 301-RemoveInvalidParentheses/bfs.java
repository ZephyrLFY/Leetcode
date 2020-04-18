import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

class Solution {
    private Set<String> res = new HashSet<String>();
    private Set<String> curLevel = new HashSet<String>();

    /* DFS
     * temp: 目前已得到的String，index表示接下来该分析的位置
     * left/rightCount: num of '(' or ')' in temp
     * count: How many removes have been done
     * 可行结果：leftCount == rightCount, and reach the end of s
     * if count > minRemove, 本次的遍历无效，清空
     * */
    public List<String> removeInvalidParentheses(String s) {
        curLevel.add(s);
        while(true) {
            for (String temp : curLevel)
                if (isValid(temp)) res.add(temp);
            if (!res.isEmpty()) return new ArrayList<String>(res);

            var nextLevel = new HashSet<String>();
            for (String temp : curLevel) {
                for (int i = 0; i < temp.length(); i++) {
                    char cur = temp.charAt(i);
                    if (cur == '(' || cur == ')') {
                        StringBuffer buffer = new StringBuffer(temp);
                        buffer.deleteCharAt(i);
                        nextLevel.add(buffer.toString());
                        
                    }
                }
                
            }
            
            curLevel = nextLevel;
        }    
    }

    public boolean isValid(String temp) {
        int len = temp.length();
        int count = 0;
        for (int i = 0; i < len; i++) {
            char cur = temp.charAt(i);
            if (cur == '(') count++;
            else if (cur == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }

    public static void main(String[] args) {
        var solu = new Solution();
        String s = "))(";
        List<String> res = solu.removeInvalidParentheses(s);
        for (String temp : res) {
            System.out.println(temp);
        }
    }
}