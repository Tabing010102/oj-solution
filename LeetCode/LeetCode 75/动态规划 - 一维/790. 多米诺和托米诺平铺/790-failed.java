class Solution {
    final int MAXN = 1000 + 10;
    final int MOD = (int)1e9 + 7;
    int[] f = new int[MAXN];
    public int numTilings(int n) {
        f[0] = 1;
        f[1] = 2;
        f[2] = 5;
        for (int i = 3; i < n; i++) {
            f[i] = (int)((long)f[i - 3] * 5 % MOD);
        }
        return f[n - 1];
    }
}