import java.util.HashSet;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null) return null;
        HashSet<ListNode> cache = new HashSet<>();
        ListNode scan = head;
        while (scan != null) {
            if (cache.contains(scan)) return scan;
            else {
                cache.add(scan);
                scan = scan.next;
            }
        }
        return null;
    }
}