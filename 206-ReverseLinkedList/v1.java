public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        if (head != null && head.next != null) {
            var res = reverseList(head.next);
            var temp = res;
            while (temp.next != null) temp = temp.next;
            temp.next = head;
            head.next = null;
            head = res;
        }
        
        return head;
    }

    public static void main(String[] agrs) {
        var solu = new Solution();

    }
}