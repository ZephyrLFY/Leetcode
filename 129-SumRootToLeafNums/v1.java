public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public int sumNumbers(TreeNode root) {
        return findSum(root, 0);
    }

    public int findSum(TreeNode root, int helper) {
        if (root == null) return 0;
        int temp = helper * 10 + root.val;
        if (root.left == null && root.right == null) return temp;
        return findSum(root.left, temp) + findSum(root.right, temp);
    }
}