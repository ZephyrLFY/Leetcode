class Solution {
    private List<Integer> res;
    private List<TreeNode> stack;

    /* 跟前序遍历的区别：
     * 前序遍历访问顺序：根->左->右
     * 如果我们每次添加结果的时候往前面填，则变成了右->左->根
     * 如果我们先访问右子树，再访问左子树，就变成了左->右->根，即为后序遍历的答案
     * */

    public List<Integer> postorderTraversal(TreeNode root) {
        res = new LinkedList<>();
        if (root == null) return res;
        
        stack = new LinkedList<>();
        TreeNode cur = root;
        while (cur != null || !stack.isEmpty()) {
            if (cur != null) {
                res.add(0, cur.val);
                stack.add(cur);
                cur = cur.right;
            }
            
            else {
                cur = stack.remove(stack.size() - 1);
                cur = cur.left;
            }
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