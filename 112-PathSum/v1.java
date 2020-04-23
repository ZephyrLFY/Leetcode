class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        return helper(root, sum, 0);
    }

    //必须在叶子节点判断，不能进入null节点判断
    //因为这样会导致如果root节点有一个子树是null，而且root.val == sum时判断true，但这个时候并不是root -> leaf
    public boolean helper(TreeNode root, int sum, int curSum) {
        curSum += root.val;
        
        if (root.left == null && root.right == null)
            return temp == sum;
        
        boolean left = false, right = false;
        if (root.left != null) left = helper(root.left, sum, curSum);
        if (root.right != null) right = helper(root.right, sum, curSum);
        return left || right;
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}