class Solution {
    private TreeNode res;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        res = null;
        search(root, p, q);
        return res;
    }
    //只要在当前节点上，发现p与q分别在左右子树，或者其中一个是当前节点，就发现了公共父节点
    //如果不是最近的公共父节点，则p和q会分布在这个节点的同一子树(可画图验证)
    public boolean search(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return false;
        boolean left = search(root.left, p, q);
        boolean right = search(root.right, p, q);
        if ((root == p ^ root == q) && (left ^ right) || left && right) {
            res = root;
            return true;
        }
        else return root == p || root == q || left || right;
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}