class Solution {
    //res记录答案，算法本身是在计算深度，两者之间无关联
    private int res;

    //本题理解起来有一个误区: 两点之间的直径，是从他俩的最低公共父节点开始计算的，这才是两点间的路径，不应该回到root计算
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        helper(root);
        return res;
    }

    public int helper(TreeNode root) {
        if (root == null) return 0;
        int left = helper(root.left);
        int right = helper(root.right);
        res = Math.max(res, left + right);
        return Math.max(left, right) + 1;
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}