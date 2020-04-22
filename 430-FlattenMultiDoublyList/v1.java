class Solution {
    public Node flatten(Node head) {
        if (head == null) return null;
        flattenChild(head);
        return head;
    }

    public Node flattenChild(Node head) {
        Node scan = head;
        while (scan.next != null) {
            if (scan.child != null) {
                Node temp = flattenChild(scan.child);
                Node nextNode = scan.next;
                temp.next = nextNode;
                nextNode.prev = temp;

                scan.child.prev = scan;
                scan.next = scan.child;
                scan.child = null;
            }
            scan = scan.next;
        }
        if (scan.child != null) {
            flattenChild(scan.child);
            scan.next = scan.child;
            scan.child.prev = scan;
            scan.child = null;
        }
        return scan;
    }

    public static void main(String[] args) {
        var solu = new Solution();
        // Node head = new Node(7);
        // head.next = new Node(8);
        // head.next.next = new Node(9);
        // head.next.next.next = new Node(10);
        // head.next.prev = head;
        // head.next.next.prev = head.next;
        // head.next.next.next.prev = head.next.next;
        // head.next.child = new Node(11);
        // head.next.child.next = new Node(12);
        // head.next.child.next.prev = head.next.child;
        Node head = new Node(4201);
        head.child = new Node(1937);
        head.child = new Node(3203);
        solu.flatten(head);
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }
}

class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
    Node(int x) { val = x; }
};