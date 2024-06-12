/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode build(int[] nums, int l, int r) {
        if (l > r) { return null; }
        else if (l == r) { return new TreeNode(nums[l]); }
        else {
            int m = l + (r - l) / 2;
            TreeNode lc = build(nums, l, m - 1);
            TreeNode rc = build(nums, m + 1, r);
            return new TreeNode(nums[m], lc, rc);
        }
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return build(nums, 0, nums.length - 1);
    }
}