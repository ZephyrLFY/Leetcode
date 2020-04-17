public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode dummyHead = new ListNode();
        dummyHead.next = head;
        var scan = head;
        int len = 0;
        //求出该链长度，便于卡interval翻倍次数
        while (scan != null) {
            len++;
            scan = scan.next;
        }

        for (int interval = 1; interval < len; interval <<= 1) {
            var cur = dummyHead.next; //cur表示目前该开始处理的地方
            var tail = dummyHead; //tail表示每次结果在dummyHead后面链接的位置

            while (cur != null) {
                //从cur开始的地方剪下来两条
                var left = cur;
                var right = cut(left, interval);
                cur = cut(right, interval); //更新cur表示下一次开始的位置
                
                tail.next = twoWayMerge(left, right);
                while (tail.next != null) tail = tail.next;
            }
        }
        return dummyHead.next;
    }
    
    public ListNode cut(ListNode head, int n) {
        //表示从head开始的链表上第n个Node处剪断，返回后面这条链
        ListNode temp = head;
        while (--n > 0 && temp != null) temp = temp.next;

        if (temp == null) return null;
        ListNode res = temp.next;
        temp.next = null;
        return res;
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