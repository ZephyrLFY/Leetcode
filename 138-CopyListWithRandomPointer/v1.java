import java.util.HashMap;

class Solution {
    private HashMap<Node, Node> map;

    public Node copyRandomList(Node head) {
        if (head == null) return null;

        map = new HashMap<>();
        Node newHead = new Node(head.val);
        Node scan = head;
        Node newScan = newHead;
        while (scan.next != null) {
            newScan.next = new Node(scan.next.val);
            map.put(scan, newScan);
            newScan = newScan.next;
            scan = scan.next;
        }
        map.put(scan, newScan);
        scan = head;
        newScan = newHead;
        while (scan != null) {
            if (scan.random == null) newScan.random = null;
            else {
                newScan.random = map.get(scan.random);
            }
            if (scan.next == null) break;
            scan = scan.next;
            newScan = newScan.next;
        }
        return newHead;
    }
}

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}