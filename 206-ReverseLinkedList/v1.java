public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    //双指针，cur记录当前要放到最后的Node，pre记录cur之后的，操作完在cur之前的Node
    public ListNode reverseList(ListNode head) {
        ListNode cur = new ListNode();
        ListNode pre = head;
        while (pre != null) {
            ListNode temp = pre.next;
            pre.next = cur;
            cur.next = null;
            cur = pre;
            pre = temp;
        }
        
        return cur;
    }
}