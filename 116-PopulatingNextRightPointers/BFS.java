import java.util.List;
import java.util.LinkedList;

class Solution {
    private List<List<Node>> stack;

    public Node connect(Node root) {
        if (root == null) return null;

        List<Node> first = new LinkedList<>();
        first.add(root);

        stack = new LinkedList<>();
        stack.add(first);

        while (!stack.isEmpty()) {
            List<Node> cur = new LinkedList<>();
            List<Node> last = stack.remove(0);

            int start = 0, scan = 0, len = last.size();
            while (++scan < len)
                last.get(start++).next = last.get(scan);
                
            last.get(--scan).next = null;

            for (Node temp : last) {
                if (temp.left != null) {
                    cur.add(temp.left);
                    cur.add(temp.right);
                }
            }
            
            if (!cur.isEmpty()) {
                stack.add(cur);
            }
        }
        return root;
    }

    public static void main(String[] args) {
        var solu = new Solution();
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        Node res = solu.connect(root);
    }
}

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};