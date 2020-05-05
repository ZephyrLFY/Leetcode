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
}

class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
    Node(int x) { val = x; }
};