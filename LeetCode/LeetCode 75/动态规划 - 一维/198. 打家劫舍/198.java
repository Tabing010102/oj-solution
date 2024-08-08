class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) { return nums[0]; }
        int[] f = new int[nums.length];
        int[] d = nums;
        f[0] = d[0];
        f[1] = Math.max(f[0], d[1]);
        for (int i = 2; i < d.length; i++) {
            f[i] = Math.max(f[i - 2] + d[i], f[i - 1]);
        }
        return f[d.length - 1];
    }
}