import java.util.Arrays;

class Solution {
    public int minPathSum(int[][] grid) {
        int[][] G = grid;
        int[][] f = new int[G.length][G[0].length];
        for (int i = 0; i < f.length; i++) {
            Arrays.fill(f[i], Integer.MAX_VALUE / 2);
        }
        f[0][0] = G[0][0];
        for (int i = 0; i < f.length; i++) {
            int[] f2 = f[i];
            for (int j = 0; j < f2.length; j++) {
                if (j + 1 < f2.length) {
                    f2[j + 1] = Math.min(f2[j + 1], G[i][j + 1] + f2[j]);
                }
                if (i + 1 < f.length) {
                    f[i + 1][j] = Math.min(f[i + 1][j], G[i + 1][j] + f[i][j]);
                }
            }
        }
        return f[f.length - 1][f[0].length - 1];
    }
}