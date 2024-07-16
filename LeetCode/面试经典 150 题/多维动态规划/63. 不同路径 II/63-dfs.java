import java.util.Arrays;

class Solution {
    int[][] G;
    int[][] f;
    int dp(int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (G[i][j] > 0) {
            return 0;
        }
        if (f[i][j] > 0) {
            return f[i][j];
        }
        return f[i][j] = dp(i - 1, j) + dp(i, j - 1);
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        G = obstacleGrid;
        f = new int[G.length][G[0].length];
        for (int i = 0; i < f.length; i++) {
            Arrays.fill(f[i], 0);
        }
        f[0][0] = 1;
        return dp(f.length - 1, f[0].length - 1);
    }
}