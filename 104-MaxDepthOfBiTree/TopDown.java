class Solution {
    private int res;

    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        helper(root, 1);
        return res;
    }

    public void helper(TreeNode root, int depth) {
        if (root == null) return;
        res = Math.max(res, depth);
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