class Solution {
    private List<Integer> res;

    public List<Integer> preorderTraversal(TreeNode root) {
        res = new ArrayList<Integer>();
        if (root != null)
            helper(root);
        return res;
    }

    public void helper(TreeNode root) {
        if (root == null) return;
        res.add(root.val);
        helper(root.left);
        helper(root.right);
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}