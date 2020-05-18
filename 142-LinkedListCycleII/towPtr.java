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
        /* First, check if there is a loop, then:
         * Assume slow pointer has walked s steps, so quick pointer walked 2 * s steps,
         *  and there are \a steps from head to the start of loop, \b steps in loop, so quick has also walked s + nb steps
         * s + nb == 2 * s -> s == nb
         * We can get this: slow has walked nb steps, quick walked 2nb steps
         * if a pointer want to get the start of loop, it should walk \a + nb steps
         * so slow pointer still need to walk \a steps, which equals to number of steps between head and start of loop.
         * so we can put quick back to head, let slow and faster walk one step each time together
         * when they meet, they will both be the start of loop
         * */
        ListNode slow = head, quick = head;
        do {
            if (quick == null || quick.next == null) return null;
            slow = slow.next;
            quick = quick.next.next;
        } while (slow != quick);
        
        quick = head;
        while (quick != slow) {
            quick = quick.next;
            slow = slow.next;
        }
        return slow;
    }
}