public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public boolean isPalindrome(ListNode head) {
        //要求O(n)runtime, O(1)内存，所以找到一半部分，反转后半部分，然后比较即可
        //这样会改变原链表，如果不改的话就得放到数组里，但是那样就是O(n)内存了
        if (head == null || head.next == null) return true;
        ListNode slow = head, quick = head;
        while (quick != null && quick.next != null) {
            slow = slow.next;
            quick = quick.next.next;
        }
        slow = reverseList(slow);
        while (head != null && slow != null) {
            if (head.val == slow.val) {
                head = head.next;
                slow = slow.next;
            }
            else return false;
        }
        return true;
    }

    public ListNode reverseList(ListNode head) {
        if (head != null && head.next != null) {
            var res = reverseList(head.next);
            head.next.next = head;
            head.next = null;
            head = res;
        }
        
        return head;
    }
}