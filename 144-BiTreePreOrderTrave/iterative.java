import java.util.List;

class Solution {
    private List<Integer> res;
    private List<TreeNode> stack;

    public List<Integer> preorderTraversal(TreeNode root) {
        res = new ArrayList<>();
        if (root == null) return res;
        
        stack = new LinkedList<>();
        TreeNode cur = root;
        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                res.add(cur.val);
                stack.add(cur);
                cur = cur.left;
            }
            cur = stack.remove(stack.size() - 1);
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