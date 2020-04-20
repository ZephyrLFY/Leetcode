import java.util.HashMap;
import java.util.ArrayList;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private HashMap<Integer, Integer> cache = new HashMap<>();
    private int max = 0;

    public int[] findFrequentTreeSum(TreeNode root) {
        if (root == null) return new int[0];
        ArrayList<Integer> res = new ArrayList<>();
        childSum(root);
        for (int i : cache.keySet()) {
            if (cache.get(i) == max) res.add(i);
        }
        int[] result = new int[res.size()];
        for(int i = 0; i < result.length; i++){
            result[i] = res.get(i);
        }
        return result;
    }

    public int childSum(TreeNode root) {
        if (root == null) return 0;
        int sum = childSum(root.left) + childSum(root.right) + root.val;
        cache.put(sum,cache.getOrDefault(sum,0)+1);
        max = Math.max(max,cache.get(sum));
        return sum;
    }
}