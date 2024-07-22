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
        f[0][1] = -d[0];
        f[0][2] = -INF;
        f[0][3] = -INF;
        f[0][4] = -INF;
        for (int i = 0; i < d.length - 1; i++) {
            f[i + 1][1] = Math.max(f[i][1], f[i][0] - d[i + 1]);
            f[i + 1][2] = Math.max(f[i][2], f[i][1] + d[i + 1]);
            f[i + 1][3] = Math.max(f[i][3], f[i][2] - d[i + 1]);
            f[i + 1][4] = Math.max(f[i][4], f[i][3] + d[i + 1]);
        }
        int dpv = 0;
        dpv = Math.max(dpv, f[d.length - 1][2]);
        dpv = Math.max(dpv, f[d.length - 1][4]);
        return dpv;
    }
}