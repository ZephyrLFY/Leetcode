public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || head.next == null) return null;
        ListNode quick = head, slow = head;
        int temp = n;
        while (quick.next != null) {
            quick = quick.next;
            if (--temp < 0) slow = slow.next;
        }

        if (slow == head && temp ==1) head = head.next;
        else if (slow.next.next == null) slow.next = null;
        else slow.next = slow.next.next;

        return head;
    }
}