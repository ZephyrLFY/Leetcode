import java.util.HashSet;

public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        HashSet<ListNode> cache = new HashSet<>();
        while (headA != null || headB != null) {
            if (headA != null) {
                if (cache.contains(headA)) return headA;
                cache.add(headA);
                headA = headA.next;
            }
            if (headB != null) {
                if (cache.contains(headB)) return headB;
                cache.add(headB);
                headB = headB.next;
            }
        }
        return null;
    }
}