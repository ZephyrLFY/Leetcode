public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        //拼接法：把长短链表接在一起，分别长的在前与短的在前，然后用两个指针从头开始走
        //假设A长，B短，listA从A开始走，listB从B开始，到了两个指针相遇的时候，就到了交接处
        //因为两者交接处以后的部分是一致的，所以将两者接到一起以后，不管谁在前，整条链的后面有一部分是一样的
        //所以listA和listB一起走，最后一定会相遇

        if (headA == null || headB == null) return null;
        ListNode listA = headA, listB = headB;
        while (listA != listB) {
            listA = listA != null ? listA.next : headB;
            listB = listB != null ? listB.next : headA;
        }
        return listA;
    }
}