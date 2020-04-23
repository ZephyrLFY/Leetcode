import java.util.List;
import java.util.LinkedList;

class Solution {
    private List<List<TreeNode>> stack;
    private List<List<Integer>> res;

    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return new LinkedList<>();

        List<TreeNode> first = new LinkedList<>();
        List<Integer> firstVal = new LinkedList<>();
        first.add(root);
        firstVal.add(root.val);

        stack = new LinkedList<>();
        res = new LinkedList<>();
        stack.add(first);
        res.add(firstVal);

        while (!stack.isEmpty()) {
            List<TreeNode> cur = new LinkedList<>();
            List<Integer> curVal = new LinkedList<>();
            for (TreeNode temp : stack.remove(0)) {
                if (temp.left != null) {
                    cur.add(temp.left);
                    curVal.add(temp.left.val);
                }
                if (temp.right != null) {
                    cur.add(temp.right);
                    curVal.add(temp.right.val);
                }
            }
            
            if (!cur.isEmpty()) {
                stack.add(cur);
                res.add(curVal);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        var solu = new Solution();
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);
        List<List<Integer>> res = solu.levelOrder(root);
        for (List<Integer> level : res) {
            for (int val : level) {
                System.out.print(val + "\t");
            }
        }
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}