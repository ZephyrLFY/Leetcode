public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = l1;
        int carry = 0; // Keep track of the carry digit
        while (l1 != null) {
            l1.val += carry + (l2 != null ? l2.val : 0); // Add l2.val and carry to l1.val
            carry = l1.val / 10;
            l1.val = l1.val % 10;
            if (l1.next == null && l2 != null) { // if l1.next is null, link l1.next to l2.next and set l2 to null
                l1.next = l2.next;
                l2 = null;
            }
            if (l1.next == null && carry == 1) { // Add new tail for the carry
                l1.next = new ListNode(carry);
                l1 = l1.next;
            }
            l1 = l1.next;
            if (l2 != null) {
                l2 = l2.next;
            }
        }
        return head;
    }
}