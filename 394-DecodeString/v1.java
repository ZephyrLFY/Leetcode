class Solution {
    public String decodeString(String s) {
        return dfs(s, 0)[0];
    }

    /* 返回的String[]里面，第一个位置是索引，第二个是字符串
    * 索引是跳过当前这组[]以后的索引位置
    * 字符串是这组[]中的字符串decode后的String
    * 而第一层递归，返回的String[]中只有String res作为答案*/

    private String[] dfs(String s, int i) {
        StringBuilder res = new StringBuilder();
        int multi = 0;
        while(i < s.length()) {
            if(s.charAt(i) >= '0' && s.charAt(i) <= '9') 
                multi = multi * 10 + Integer.parseInt(String.valueOf(s.charAt(i))); 
            else if(s.charAt(i) == '[') {
                String[] tmp = dfs(s, i + 1);
                i = Integer.parseInt(tmp[0]);
                while(multi > 0) {
                    res.append(tmp[1]);
                    multi--;
                }
            }
            else if(s.charAt(i) == ']') //跳出本层，返回索引与本层字符串
                return new String[] { String.valueOf(i), res.toString() };
            else 
                res.append(String.valueOf(s.charAt(i)));
            i++;
        }
        return new String[] { res.toString() };
    } 
}