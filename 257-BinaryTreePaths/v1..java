public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private List<String> res;

    public List<String> binaryTreePaths(TreeNode root) {
        res = new ArrayList<String>();
        if (root == null) return res;
        addPaths(root, "");
        return res;
    }

    public void addPaths(TreeNode root, String temp) {
        if (root != null) {
            String newStr = temp + Integer.toString(root.val);
            if (root.left == null && root.right == null) {
                res.add(newStr);
                return;
            }
            newStr += "->";
            addPaths(root.left,  newStr);
            addPaths(root.right, newStr);
        }
    }
}