// prefix & suffix array
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] d = nums;
        int[] pre = new int[d.length];
        int[] suf = new int[d.length];
        // init
        pre[0] = d[0];
        for (int i = 1; i < pre.length; i++) {
            pre[i] = pre[i - 1] * d[i];
        }
        suf[suf.length - 1] = d[suf.length - 1];
        for (int i = suf.length - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] * d[i];
        }
        // ans
        int[] ans = new int[d.length];
        for (int i = 0; i < d.length; i++) {
            ans[i] = (i > 0 ? pre[i - 1] : 1)
                * ((i < d.length - 1) ? suf[i + 1] : 1);
        }
        return ans;
    }
}