class MyLinkedList {
    private MyNode head;

    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = null;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (head == null || index < 0) return -1;
        MyNode scan = head;
        for (int i = 0; i < index; i++) {
            if (scan.next != null) scan = scan.next;
            else return -1;
        }
        return scan.val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        MyNode temp = new MyNode(val);
        temp.next = head;
        head = temp;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        MyNode temp = new MyNode(val);
        if (head != null) {
            MyNode scan = head;
            while (scan.next != null) scan = scan.next;
            scan.next = temp;
        }
        else head = temp;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index < 0) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        
        if (head == null) return;
        MyNode scan = head;
        for (int i = 0; i < index - 1; i++) {
            if (scan.next != null) scan = scan.next;
            else return;
        }
        if (scan.next == null) {
            addAtTail(val);
            return;
        }
        MyNode temp = new MyNode(val);
        MyNode behind = scan.next;
        scan.next = temp;
        temp.next = behind;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index < 0 || head == null) return;
        if (index == 0) {
            if (head.next == null) head = null;
            else head = head.next;
            return;
        }
        MyNode scan = head;
        for (int i = 0; i < index - 1; i++) {
            if (scan.next != null) scan = scan.next;
            else return;
        }
        if (scan.next != null) scan.next = scan.next.next;
    }
}

public class MyNode {
    int val;
    MyNode next;
    MyNode(int value) {val = value; next = null;}
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */