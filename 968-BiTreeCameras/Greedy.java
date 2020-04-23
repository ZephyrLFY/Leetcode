// public enum Status {
//     Monitered, Unmonitered, Placed, Unkown;
// }

/* We use 4 numbers to represent the status of a Node
 * 0: Unchecked; 1: Not monitered; 2: Monitered; 3:Monitered and has a camera;
 * A camera cannot be placed in a leaf node, because it can be monitered by its parent.
 * */

class Solution {
    private int res;

    public int minCameraCover(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 1;
        res = 0;

        //Status status = check(root);
        int status = check(root);
        //if (status == Status.Unmonitered)
        if (status == 1)
            res++;
        return res;
    }

    //public Status check(TreeNode root) {
    public int check(TreeNode root) {
        if (root.left == null && root.right == null)
            //return Status.Unmonitered;
            return 1;

        //Status left = Status.Unkown;
        int left = 0;
        if (root.left != null)
            left = check(root.left);

        //Status right = Status.Unkown;
        int right = 0;
        if (root.right != null)
            right = check(root.right);

        //if (left == Status.Unmonitered || right == Status.Unmonitered) {
        if (left == 1 || right == 1) {
            res++;
            //return Status.Placed;
            return 3;
        }

        // if ((left == Status.Monitered && right == Status.Monitered) 
        // || (left == Status.Monitored && right == Status.Unkown) 
        // || (left == Status.Unkown && right == Status.Monitered)) {
        //     return Status.Unmonitered;
        // }
        // else if (left == Status.Placed || right == Status.Placed) {
        //     return Status.Monitered;
        // }
        if ((left == 2 && right == 2) 
        || (left == 2 && right == 0) 
        || (left == 0 && right == 2)) {
            return 1;
        }
        else if (left == 3 || right == 3) {
            return 2;
        }

        //return Status.Placed;
        return 3;
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}