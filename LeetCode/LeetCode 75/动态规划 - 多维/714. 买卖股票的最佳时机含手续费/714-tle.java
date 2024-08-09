import java.util.Arrays;

class Solution {
    final int MAXN = (int)5e4 + 10;
    // f[i] -> prices[i - 1]
    int[][] f = new int[MAXN][2];
    int[] p;
    int fee;
    int dp(int i, int j) {
        if (i == 0) { return 0; }
        if (f[i][j] >= 0) { return f[i][j]; }
        for (int k = 0; k <= i; k++) {
            if (j == 0) {
                f[i][j] = Math.max(f[i][j], dp(k, 0));
                if (k > 0) { f[i][j] = Math.max(f[i][j], dp(k, 1) + p[k - 1] - fee); }
            } else {
                if (k > 0) { f[i][j] = Math.max(f[i][j], dp(k, 0) - p[k - 1]); }
            }
        }
        return f[i][j];
    }
    public int maxProfit(int[] prices, int fee) {
        p = prices;
        this.fee = fee;
        for (int i = 0; i <= prices.length; i++) {
            Arrays.fill(f[i], -MAXN);
        }
        // dp(p.length, 0);
        // for (int i = 0; i <= p.length; i++) {
        //     System.out.print("%d ".formatted(dp(i, 0)));
        // }
        // System.out.println();
        // for (int i = 0; i <= p.length; i++) {
        //     System.out.print("%d ".formatted(dp(i, 1)));
        // }
        return dp(p.length, 0);
    }
}