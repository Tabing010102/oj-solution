// prefix & suffix array
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] d = nums;
        int[] ans = new int[d.length];
        // init pre
        ans[0] = d[0];
        for (int i = 1; i < ans.length; i++) {
            ans[i] = ans[i - 1] * d[i];
        }
        // ans
        int suf = 1;
        for (int i = d.length - 1; i >= 0; i--) {
            ans[i] = suf * (i > 0 ? ans[i - 1] : 1);
            suf *= d[i];
        }
        return ans;
    }
}