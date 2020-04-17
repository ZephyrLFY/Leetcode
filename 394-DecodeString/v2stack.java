import java.util.LinkedList;

class Solution {
    public String decodeString(String s) {
        String res = "";
        int times = 0;

        LinkedList<Integer> nums = new LinkedList<>();
        LinkedList<String> stack = new LinkedList<>();

        for (Character c : s.toCharArray()) {
            if (c == '[') { //进入更深一层，须保留本层的res和times
                nums.add(times);
                stack.add(res);
                res = "";
                times = 0;
            }
            else if (c == ']') { //将本层数据处理完
                int multi = nums.removeLast();
                String temp = "";
                for (int i = 0; i < multi; i++) temp += res;
                res = stack.removeLast() + temp;
            }
            else if (c >= '0' && c <= '9') times = times * 10 + Character.getNumericValue(c);
            else res += String.valueOf(c); //本层中的字母
        }

        return res;
    }
}