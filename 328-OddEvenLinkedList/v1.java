class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode odd = head, even = head.next, scan = even;
        while ((odd.next != null && odd.next.next != null) || (scan!= null && scan.next != null)) {
            if (odd.next != null && odd.next.next != null) {
                odd.next = odd.next.next;
                odd = odd.next;
            }
            if (scan != null && scan.next != null) {
                scan.next = scan.next.next;
                scan = scan.next;
            }
        }
        odd.next = even;
        return head;
    }
}

public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}