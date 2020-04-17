public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode preMid = new ListNode();
        ListNode mid = head;
        ListNode scan = head;
        //通过快慢指针找到中点
        while (scan != null && scan.next != null) {
            preMid = mid;
            mid = mid.next;
            scan = scan.next.next;
        }
        preMid.next = null;

        //递归调用
        return twoWayMerge(sortList(head), sortList(mid));
    }

    //leetcode21 - Merge 2 sorted list
    public ListNode twoWayMerge(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();
        ListNode temp = head;
        while (l1 != null && l2 != null) {
            if (l1.val > l2.val) {
                temp.next = l2;
                l2 = l2.next;
            }
            else {
                temp.next = l1;
                l1 = l1.next;
            }
            temp = temp.next;
        }
        if (l1 != null) temp.next = l1;
        else temp.next = l2;
        return head.next;
    }
}