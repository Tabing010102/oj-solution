class Solution {
    char[][] G;
    int[][] d;
    int[][] f;
    // f[i][j], G[?][?] -> G[i][j] max size
    public int maximalSquare(char[][] matrix) {
        G = matrix;
        d = new int[G.length][G[0].length];
        f = new int[G.length][G[0].length];
        for (int i = 0; i < G.length; i++) {
            for (int j = 0; j < G[i].length; j++) {
                d[i][j] = (i > 0 ? d[i - 1][j] : 0)
                    + (j > 0 ? d[i][j - 1] : 0)
                    + (G[i][j] == '1' ? 1 : 0)
                    - ((i > 0 && j > 0) ? d[i - 1][j - 1] : 0);
            }
        }
        for (int j = 0; j < G[0].length; j++) {
            f[0][j] = G[0][j] == '1' ? 1 : 0;
        }
        for (int i = 0; i < G.length; i++) {
            f[i][0] = G[i][0] == '1' ? 1 : 0;
        }
        for (int i = 0; i < G.length - 1; i++) {
            for (int j = 0; j < G[i].length - 1; j++) {
                if (G[i][j] == '0') {
                    f[i + 1][j + 1] = Math.max(f[i + 1][j + 1], G[i + 1][j + 1] == '1' ? 1 : 0);
                } else {
                    for (int k = f[i][j]; k >= 0; k--) {
                        if (isFullOne(i - k + 1, j + 1, i + 1, j + 1) && isFullOne(i + 1, j - k + 1, i + 1, j + 1)) {
                            f[i + 1][j + 1] = Math.max(f[i + 1][j + 1], k + 1);
                            break;
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < G.length; i++) {
        //     System.out.println();
        //     for (int j = 0; j < G[i].length; j++) {
        //         System.out.print(String.valueOf(d[i][j]) + " ");
        //     }
        // }
        // for (int i = 0; i < G.length; i++) {
        //     System.out.println();
        //     for (int j = 0; j < G[i].length; j++) {
        //         System.out.print(String.valueOf(f[i][j]) + " ");
        //     }
        // }
        int ans = 0;
        for (int i = 0; i < G.length; i++) {
            for (int j = 0; j < G[i].length; j++) {
                ans = Math.max(ans, f[i][j]);
            }
        }
        return ans * ans;
    }
    boolean isFullOne(int x1, int y1, int x2, int y2) {
        int sum = d[x2][y2]
            - (x1 > 0 ? d[x1 - 1][y2] : 0)
            - (y1 > 0 ? d[x2][y1 - 1] : 0)
            + ((x1 > 0 && y1 > 0) ? d[x1 - 1][y1 - 1] : 0);
        return sum == (x2 - x1 + 1) * (y2 - y1 + 1);
    }
}