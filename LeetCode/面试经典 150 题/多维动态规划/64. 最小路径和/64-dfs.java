import java.util.Arrays;

class Solution {
    int[][] G;
    int[][] f;
    int dp(int i, int j) {
        if (i < 0 || j < 0) {
            return Integer.MAX_VALUE / 2;
        }
        if (f[i][j] != -1) {
            return f[i][j];
        }
        return f[i][j] = G[i][j] + Math.min(dp(i - 1, j), dp(i, j - 1));
    }
    public int minPathSum(int[][] grid) {
        G = grid;
        f = new int[G.length][G[0].length];
        for (int i = 0; i < f.length; i++) {
            Arrays.fill(f[i], -1);
        }
        f[0][0] = G[0][0];
        return dp(G.length - 1, G[0].length - 1);
    }
}