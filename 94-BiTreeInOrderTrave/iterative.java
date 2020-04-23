class Solution {
    private List<Integer> res;
    private List<TreeNode> stack;

    public List<Integer> inorderTraversal(TreeNode root) {
        res = new ArrayList<>();
        if (root == null) return res;
        
        stack = new LinkedList<>();
        TreeNode cur = root;
        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                stack.add(cur);
                cur = cur.left;
            }
            cur = stack.remove(stack.size() - 1);
            res.add(cur.val);
            cur = cur.right;
        }
        return res;
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}