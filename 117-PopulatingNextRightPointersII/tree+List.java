class Solution {
    public Node connect(Node root) {
        if (root == null) return null;
        Node head = root, pre = null, cur = head;
        //cur: 本层List的游标
        //head: 下一层的开头
        //pre: 下一层的游标
        while (head != null) {
            cur = head;
            pre = head = null;
            while (cur != null) {
                if (cur.left != null) {
                    if (pre == null)
                        pre = head = cur.left;
                    else {
                        pre.next = cur.left;
                        pre = pre.next;
                    }
                }
                if (cur.right != null) {
                    if (pre == null)
                        pre = head = cur.right;
                    else {
                        pre.next = cur.right;
                        pre = pre.next;
                    }
                }
                cur = cur.next;
            }
        }
        return root;
    }
};

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