class Solution {
    private long lastVal = Long.MIN_VALUE;
    //比较过程:
    //lastVal = root的左子树中最右子树的值
    //比较lastVal与root.val
    //lastVal = root.val
    //比较lastVal与root右子树中最左子树的值

    public boolean isValidBST(TreeNode root) {
        if (root == null)
            return true;
        if (!isValidBST(root.left))
            return false;
        if (root.val <= lastVal) 
            return false;
        lastVal = (long) root.val;
        if (!isValidBST(root.right))
            return false;
        return true;
    }
}