class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;

        int len = 1, nums = k;
        ListNode slow = head, fast = head;
        while (fast.next != null && nums > 0) {
            len++;
            nums--;
            fast = fast.next;
        }

        if (nums > 0) {
            nums = k % len;
            if (nums == 0) return head;
            fast = head;
            while (nums > 0) {
                nums--;
                fast = fast.next;
            }
        }
        
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }

        ListNode temp = slow.next, scan = temp;
        slow.next = null;
        while (scan.next != null)
            scan = scan.next;
        scan.next = head;
        return temp;
    }

    public static void main(String[] args) {
        var solu = new Solution();
        ListNode head = new ListNode(1);
        // head.next = new ListNode(2);
        // head.next.next = new ListNode(3);
        // head.next.next.next = new ListNode(4);
        // head.next.next.next.next = new ListNode(5);
        ListNode res = solu.rotateRight(head, 10);
        while (res.next != null) {
            System.out.print(res.val + "\t");
            res = res.next;
        }
        System.out.println(res.val);
    }
}

public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}