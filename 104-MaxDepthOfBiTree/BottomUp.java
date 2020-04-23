class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        return helper(root);
    }

    public int helper(TreeNode root) {
        if (root == null) return 0;
        return Math.max(helper(root.left), helper(root.right)) + 1;
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}