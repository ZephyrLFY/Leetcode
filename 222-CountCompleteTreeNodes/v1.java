class Solution {
    private int depth, curLevel, res;

    public int countNodes(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null) return 1;
        findLeaf(root);
        int notLeaf = 0;
        for (int i = 0; i < depth; i++) {
            notLeaf += Math.pow(2, i - 1);
        }
        return notLeaf + res;
    }

    public void findLeaf(TreeNode root) {
        if (root == null) return;
        curLevel++;
        if (depth != 0 && curLevel == depth) res++;
        else if (depth == 0 && root.left == null) {
            depth = curLevel;
            res++;
        }
        else {
            findLeaf(root.left);
            findLeaf(root.right);
        }
        curLevel--;
        return;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        var solu = new Solution();
        int result = solu.countNodes(root);
        System.out.println(result);
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}