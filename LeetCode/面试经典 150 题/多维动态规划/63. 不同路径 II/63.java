import java.util.Arrays;

class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int[][] G = obstacleGrid;
        int[][] f = new int[G.length][G[0].length];
        for (int i = 0; i < f.length; i++) {
            Arrays.fill(f[i], 0);
        }
        f[0][0] = 1;
        for (int i = 0; i < f.length; i++) {
            int[] f2 = f[i];
            for (int j = 0; j < f2.length; j++) {
                if (G[i][j] > 0) {
                    f[i][j] = 0;
                    continue;
                }
                if (j + 1 < f2.length) {
                    if (i > 0) {
                        f2[j + 1] = f2[j] + f[i - 1][j + 1];
                    } else {
                        f2[j + 1] = f2[j];
                    }
                }
                if (i + 1 < f.length) {
                    f[i + 1][j] = f[i][j];
                }
            }
        }
        // for (int i = 0; i < f.length; i++) {
        //     for (int j = 0; j < f[i].length; j++) {
        //         System.out.print(Integer.valueOf(f[i][j]).toString() + " ");
        //     }
        //     System.out.println();
        // }
        return f[f.length - 1][f[0].length - 1];
    }
}