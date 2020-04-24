class Solution {
    public boolean isValidBST(TreeNode root) {
        return helper(root, Long.MAX_VALUE, Long.MIN_VALUE);
    }

    public boolean helper(TreeNode root, long upper, long lower) {
        if (root == null) return true;
        if (upper <= root.val || lower >= root.val) return false;
        if (!helper(root.left, root.val, lower) || !helper(root.right, upper, root.val)) return false;
        return true;
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}