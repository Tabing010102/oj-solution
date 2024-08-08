import java.util.Arrays;

class Solution {
    final int MAXN = 37 + 1;
    int[] f = new int[MAXN];
    int dp(int i) {
        if (i == 0) { return 0; }
        if (i == 1 || i == 2) { return 1; }
        if (f[i] > 0) { return f[i]; }
        return f[i] = dp(i - 1) + dp(i - 2) + dp(i - 3);
    }
    public int tribonacci(int n) {
        Arrays.fill(f, -1);
        return dp(n);
    }
}