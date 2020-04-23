import java.util.HashMap;

class Solution {
    private HashMap<Integer, Integer> map;
    private int[] preorder;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int len = inorder.length;
        map = new HashMap<>();
        for (int i = 0; i < len; i++) map.put(inorder[i], i);
        this.preorder = preorder;
        return buildTree(0, len - 1, 0, len - 1);
    }

    //重点在于ps，pe的计算
    public TreeNode buildTree(int ps, int pe, int is, int ie) {
        if (pe < ps || ie < is) return null;

        int rootVal = preorder[ps];
        int mid = map.get(rootVal);

        TreeNode root = new TreeNode(rootVal);
        root.left = buildTree(ps + 1, ps + mid - is, is, mid - 1);
        root.right = buildTree(ps + mid - is + 1, pe, mid + 1, ie);
        return root;
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}