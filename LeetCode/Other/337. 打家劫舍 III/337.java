// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    TreeNode f;
    public int rob(TreeNode root) {
        f = build(root);
        return dfs(f, root);
    }

    TreeNode build(TreeNode n) {
        if (n == null) { return null; }
        TreeNode cur = new TreeNode(-1);
        cur.left = build(n.left);
        cur.right = build(n.right);
        return cur;
    }

    int dfs(TreeNode fc, TreeNode dc) {
        if (fc == null) { return 0; }
        if (fc.val != -1) { return fc.val; }
        if (fc.left == null && fc.right == null) { return fc.val = dc.val; }
        int l1 = dfs(fc.left, dc.left) + dfs(fc.right, dc.right);
        int l2 = dc.val;
        if (fc.left != null) {
            l2 += dfs(fc.left.left, dc.left.left);
            l2 += dfs(fc.left.right, dc.left.right);
        }
        if (fc.right != null) {
            l2 += dfs(fc.right.left, dc.right.left);
            l2 += dfs(fc.right.right, dc.right.right);
        }
        return fc.val = Math.max(l1, l2);
    }
}