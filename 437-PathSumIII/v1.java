class Solution {
    private int[] cache;

    public int pathSum(TreeNode root, int sum) {
        cache = new int[1000];
        return helper(root, sum, 0);
    }

    public int helper(TreeNode root, int sum, int index) {
        if (root == null) return 0;

        cache[index] = root.val;
        int temp = 0;
        int curSum = 0;

        //Hint: For every node, count the array ends with this node, not starts with it...
        for (int i = index; i >= 0; i--) {
            temp += cache[i];
            if (temp == sum) curSum++;
        }
        
        return curSum + helper(root.left, sum, index + 1) + helper(root.right, sum, index + 1);
    }

    public static void main(String[] args) {
        var solu = new Solution();
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(-2);
        root.right = new TreeNode(-3);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        //root.left.left.left = new TreeNode(3);
        root.left.left.right = new TreeNode(-1);
        //root.left.right.right = new TreeNode(1);
        root.right.left = new TreeNode(-2);
        System.out.print(solu.pathSum(root, 3));
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}