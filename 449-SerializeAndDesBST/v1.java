import java.util.LinkedList;

public class Codec {
    //BST can only use preorder or postorder, because if we use inorder, the string needs to be sorted
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) return "";
        StringBuilder res = postOrder(root, new StringBuilder());
        res.deleteCharAt(res.length() - 1);
        return res.toString();
    }

    public StringBuilder postOrder(TreeNode root, StringBuilder temp) {
        if (root == null) return temp;
        postOrder(root.left, temp);
        postOrder(root.right, temp);
        temp.append(root.val);
        temp.append(',');
        return temp;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.isEmpty()) return null;
        LinkedList<Integer> cache = new LinkedList<>();
        for (String temp : data.split(","))
            cache.addLast(Integer.valueOf(temp));
        return helper(Integer.MIN_VALUE, Integer.MAX_VALUE, cache);
    }

    public TreeNode helper(int min, int max, LinkedList<Integer> cache) {
        if (cache.isEmpty()) return null;
        int val = cache.peekLast();
        if (val < min || val > max) return null;

        cache.pollLast();
        TreeNode root = new TreeNode(val);
        root.right = helper(val, max, cache);
        root.left = helper(min, val, cache);
        return root;
    }

    public void printTree(TreeNode root) {
        if (root == null) return;
        printTree(root.left);
        System.out.print(root.val + "\t");
        printTree(root.right);
    }

    public static void main(String[] args) {
        var solu = new Codec();
        String data = "12345678";
        TreeNode root = solu.deserialize(data);
        System.out.println(solu.serialize(root));
        solu.printTree(root);
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));