import java.util.Arrays;

class Solution {
    final int MAXN = (int)5e4 + 10;
    // f[i] -> prices[i - 1]
    // 0 sold 1 bought
    int[][] f = new int[MAXN][2];
    int[] p;
    int fee;
    public int maxProfit(int[] prices, int fee) {
        p = prices;
        this.fee = fee;
        for (int i = 0; i <= prices.length; i++) {
            Arrays.fill(f[i], -MAXN);
        }
        f[0][0] = 0;
        f[0][1] = -MAXN;
        for (int i = 0; i < p.length; i++) {
            f[i + 1][0] = Math.max(f[i][0], f[i][1] + p[i] - fee);
            f[i + 1][1] = Math.max(f[i][1], f[i][0] - p[i]);
        }
        // for (int i = 0; i <= p.length; i++) {
        //     System.out.print("%d ".formatted(f[i][0]));
        // }
        // System.out.println();
        // for (int i = 0; i <= p.length; i++) {
        //     System.out.print("%d ".formatted(f[i][1]));
        // }
        return f[p.length][0];
    }
}