import java.util.Arrays;

class Solution {
    private static final int INF = 400010;
    int[] d;
    int[][] f;
    // f[i][j] 0-i days state j
    // state: 0 0buy0sell 1 1buy0sell 2 1buy1sell 3 2buy1sell 4 2buy2sell
    public int maxProfit(int k, int[] prices) {
        d = prices;
        if (d.length < 2) {
            return 0;
        }
        k *= 2;
        if (k > d.length) {
            k = d.length;
            if (k % 2 == 1) {
                k--;
            }
        }
        f = new int[prices.length][k + 1];
        f[0][1] = -d[0];
        for (int j = 2; j <= k; j++) {
            f[0][j] = -INF;
        }
        for (int i = 0; i < d.length - 1; i++) {
            for (int j = 1; j <= k; j++) {
                if (j % 2 == 1) {
                    f[i + 1][j] = Math.max(f[i][j], f[i][j - 1] - d[i + 1]);
                } else {
                    f[i + 1][j] = Math.max(f[i][j], f[i][j - 1] + d[i + 1]);
                }
            }
        }
        int dpv = 0;
        for (int j = 2; j <= k; j += 2) {
            dpv = Math.max(dpv, f[d.length - 1][j]);
        }
        // for (int j = 0; j <= k; j++) {
        //     for (int i = 0; i < d.length; i++) {
        //         System.out.print(String.valueOf(f[i][j]) + " ");
        //     }
        //     System.out.println();
        // }
        return dpv;
    }
}