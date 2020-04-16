import java.util.HashMap;

class Node {
    public int key, val;
    public Node pre, next;
    public Node(int key, int val) {
        this.key = key;
        this.val = val;
    }
}

class DoubleList {
    private Node head, tail;
    private int size; //为了在插入时判断满不满

    public DoubleList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.next = tail;
        tail.pre = head;
        size = 0;
    }

    public int getSize() { return size; }

    public void addFirst(Node temp) {
        //优先级最低，刚put或者get过
        temp.next = head.next;
        temp.pre = head;
        head.next.pre = temp;
        head.next = temp;
        size++;
    }

    public void remove(Node temp) {
        //被新的value替代的点，或处于尾端因为LRU被替换
        temp.pre.next = temp.next;
        temp.next.pre = temp.pre;
        size--;
    }

    public Node removeLast() {
        //LRU策略，返回Node用来从哈希表中去除
        if (tail == head) return null;
        Node last = tail.pre;
        remove(last);
        return last;
    }
}

class LRUCache {
    private HashMap<Integer, Node> map;
    private DoubleList cache;
    private int nums;

    public LRUCache(int capacity) {
        nums = capacity;
        map = new HashMap<>();
        cache = new DoubleList();
    }
    
    public int get(int key) {
        if (!map.containsKey(key)) return -1;
        //将其拿出来放在开头
        int val = map.get(key).val;
        put(key, val);
        return val;
    }
    
    public void put(int key, int value) {
        Node temp = new Node(key, value);
        //为已经存在的Node替换新value值；或者顶替尾端Node
        if (map.containsKey(key)) cache.remove(map.get(key));
        else if (nums == cache.getSize()) {
            Node last = cache.removeLast();
            map.remove(last.key);
        }
        //更新cache与map
        cache.addFirst(temp);
        map.put(key, temp);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */