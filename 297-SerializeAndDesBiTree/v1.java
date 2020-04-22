import java.util.LinkedList;

public class Codec {
    private LinkedList<String> cache;
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) return "";
        StringBuilder res = postOrder(root, new StringBuilder());
        res.deleteCharAt(res.length() - 1);
        return res.toString();
    }

    public StringBuilder postOrder(TreeNode root, StringBuilder temp) {
        if (root == null)
            temp.append("null,");
        else {
            temp.append(root.val);
            temp.append(',');
            postOrder(root.left, temp);
            postOrder(root.right, temp);
        }
        return temp;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.isEmpty()) return null;
        cache = new LinkedList<>();
        for (String temp : data.split(","))
            cache.addLast(temp);
        return helper();
    }

    public TreeNode helper() {
        if (cache.isEmpty()) return null;
        String val = cache.pollFirst();
        if (val.equals("null")) return null;

        TreeNode root = new TreeNode(Integer.valueOf(val));
        root.right = helper();
        root.left = helper();
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
        String data = "1,2,3,null,null,4,5";
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