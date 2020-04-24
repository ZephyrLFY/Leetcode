import java.util.HashMap;

class Solution {
    private HashMap<TreeNode, Integer> minVal;
    private HashMap<TreeNode, Integer> maxVal;

    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        minVal = new HashMap<>();
        maxVal = new HashMap<>();
        return helper(root);
    }

    public boolean helper(TreeNode root) {
        int temp = root.val;

        boolean left = false, right = false;
        if (root.left != null && helper(root.left)
        && maxVal.get(root.left) < temp) {
            minVal.put(root, minVal.get(root.left));
            left = true;
        }
        else if (root.left == null) {
            minVal.put(root, temp);
            left = true;
        }
        if (!left) return false;

        if (root.right != null && helper(root.right)
        && minVal.get(root.right) > temp) {
            maxVal.put(root, maxVal.get(root.right));
            right = true;
        }
        else if (root.right == null) {
            maxVal.put(root, temp);
            right = true;
        }
        if (!right) return false;

        return true;
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}