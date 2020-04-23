class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        return helper(root.left, root.right);
    }

    public boolean helper(TreeNode left, TreeNode right) {
        if (left == null || right == null) {
            if (left == right) return true;
            else return false;
        }
        if (left.val == right.val) {
            if (helper(left.right, right.left) && helper(left.left, right.right))
                return true;
        }
        return false;
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}