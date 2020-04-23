import java.util.List;
import java.util.LinkedList;

class Solution {
    private List<List<Integer>> res;

    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return new LinkedList<>();
        res = new LinkedList<>();
        helper(root, 0);
        return res;
    }

    public void helper(TreeNode root, int depth) {
        if (root == null) return;
        if (res.size() <= depth) res.add(new LinkedList<Integer>());
        res.get(depth).add(root.val);
        helper(root.left, depth + 1);
        helper(root.right, depth + 1);
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}