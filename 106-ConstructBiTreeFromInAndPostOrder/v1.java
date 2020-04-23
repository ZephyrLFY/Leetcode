import java.util.List;
import java.util.ArrayList;

class Solution {
    //In Order: (Left SubTree) + (root) + (Right Subtree)
    //Post Order: (Left Subtree) + (Right Subtree) + (root)
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        List<Integer> A = new ArrayList<Integer>();
        for (int i : inorder) A.add(i);
        List<Integer> B = new ArrayList<Integer>();
        for (int i : postorder) B.add(i);
        return helper(A, B);
    }

    public TreeNode helper(List<Integer> inorder, List<Integer> postorder) {
        int len = inorder.size();
        if (len == 0) return null;

        int rootVal = postorder.get(len - 1);
        TreeNode root = new TreeNode(rootVal);
        int i = 0;
        while (inorder.get(i) != rootVal)
            i++;
        root.left = helper(inorder.subList(0, i), postorder.subList(0, i));
        int inStart = i + 1, postStart = i, inEnd = len, postEnd = len - 1;
        if (inEnd < inStart) inEnd = inStart;
        if (postEnd < postStart) postEnd = postStart;
            root.right = helper(inorder.subList(inStart, inEnd), postorder.subList(postStart, postEnd));
        return root;
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}