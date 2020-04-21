public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private int nums;

    public int distributeCoins(TreeNode root) {
        solveNums(root);
        return nums;
    }
    
    /* 对于每一个子节点，只要硬币数量不是1，就会发生从父节点到它or它到父节点的转移
     * 所以只要计算所有子节点与其父节点之间的传递即可
     * */
    
    public int solveNums(TreeNode root) {
        if (root == null) return 0;
        int temp = root.val;
        root.val = 1;
        temp += (solveNums(root.left) + solveNums(root.right));
        //-1是要给自己留一个
        nums += Math.abs(temp - 1);
        return temp - 1;
    }
}