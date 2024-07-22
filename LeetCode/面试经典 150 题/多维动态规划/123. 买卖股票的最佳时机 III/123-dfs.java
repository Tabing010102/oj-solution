import java.util.Arrays;

class Solution {
    private static final int INF = 400010;
    int[] d;
    int[][] f;
    // f[i][j] 0-i days state j
    // state: 0 0buy0sell 1 1buy0sell 2 1buy1sell 3 2buy1sell 4 2buy2sell
    public int maxProfit(int[] prices) {
        d = prices;
        f = new int[prices.length][5];
        for (int i = 0; i < f.length; i++) {
            Arrays.fill(f[i], -INF);
        }
        int dpv = -INF;
        dpv = Math.max(dpv, dp(d.length - 1, 0));
        dpv = Math.max(dpv, dp(d.length - 1, 2));
        dpv = Math.max(dpv, dp(d.length - 1, 4));
        // for (int j = 0; j <= 4; j++) {
        //     for (int i = 0; i < d.length; i++) {
        //         System.out.print(String.valueOf(dp(i, j)) + " ");
        //     }
        //     System.out.println();
        // }
        return dpv;
    }
    int dp(int i, int j) {
        if (j == 0) { return 0; }
        if (i < 0) { return -INF; }
        if (f[i][j] != -INF) { return f[i][j]; }
        if (j == 1 || j == 3) {
            f[i][j] = Math.max(dp(i - 1, j), dp(i - 1, j - 1) - d[i]);
        } else {
            f[i][j] = Math.max(dp(i - 1, j), dp(i - 1, j - 1) + d[i]);
        }
        // System.out.println("i=%d, j=%d, f[i][j]=%d".formatted(i, j, f[i][j]));
        return f[i][j];
    }
}