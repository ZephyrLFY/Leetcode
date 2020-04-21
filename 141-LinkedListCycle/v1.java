class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    // public boolean hasCycle(ListNode head) {
    //     if (head != null) {
    //         ListNode slow = head, quick = head;
    //         while (slow.next != null && quick.next != null && quick.next.next != null) {
    //             slow = slow.next;
    //             quick = quick.next.next;
    //             if (slow == quick) return true;
    //         }
    //     }
    //     return false;
    // }

    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) return false;
        ListNode slow = head, quick = head.next;
        while (slow != quick) {
            if (quick == null || quick.next == null) return false;
            slow = slow.next;
            quick = quick.next.next;
        }
        return true;
    }
}