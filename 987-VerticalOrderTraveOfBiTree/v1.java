import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

class Solution {
    private List<Coordinate> coor; //TreeMap and Priority Queue alse works
    
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        coor = new LinkedList<Coordinate>();
        List<List<Integer>> res = new LinkedList<>();
        res.add(new LinkedList<Integer>());

        dfs(root, 0, 0);
        Collections.sort(coor);

        int preX = coor.get(0).x;
        for (Coordinate temp : coor) {
            if (temp.x != preX) {
                preX = temp.x;
                res.add(new LinkedList<Integer>());
            }
            res.get(res.size() - 1).add(temp.val);
        }
        return res;
    }

    public void dfs(TreeNode root, int x, int y) {
        if (root != null) {
            coor.add(new Coordinate(x, y, root.val));
            dfs(root.left, x - 1, y - 1);
            dfs(root.right, x + 1, y - 1);
        }
    }
}

public class Coordinate implements Comparable<Coordinate>{
    int x, y, val;
    Coordinate(int x, int y, int val) {
        this.x = x;
        this.y = y;
        this.val = val;
    }

    @Override
    public int compareTo(Coordinate that) {
        if (this.x != that.x) return Integer.compare(this.x, that.x);
        else if (this.y != that.y) return Integer.compare(this.y, that.y);
        else return Integer.compare(this.val, that.val);
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}