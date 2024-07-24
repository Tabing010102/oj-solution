class Solution {
    char[][] G;
    int[][] d;
    int[][] f;
    // f[i][j], G[?][?] -> G[i][j] max size
    public int maximalRectangle(String[] matrix) {
        if (matrix.length == 0 || matrix[0].length() == 0) {
            return 0;
        }
        G = new char[matrix.length][];
        for (int i = 0; i < matrix.length; i++) {
            G[i] = matrix[i].toCharArray();
        }
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
        f[0][0] = G[0][0] == '1' ? 1 : 0;
        for (int j = 1; j < G[0].length; j++) {
            f[0][j] = G[0][j] == '1' ? f[0][j - 1] + 1 : 0;
        }
        for (int i = 1; i < G.length; i++) {
            f[i][0] = G[i][0] == '1' ? f[i - 1][0] + 1 : 0;
        }
        int tans = 0;
        for (int i = 0; i < G.length; i++) {
            for (int j = 0; j < G[i].length; j++) {
                if (G[i][j] == '0') {
                    // right
                    if (j < G[i].length - 1) {
                        tans = 0;
                        for (int k = i; k >= 0; k--, tans++) {
                            if (G[k][j + 1] != '1') {
                                break;
                            }
                        }
                        f[i][j + 1] = Math.max(f[i][j + 1], tans);
                    }
                    // down
                    if (i < G.length - 1) {
                        tans = 0;
                        for (int k = j; k >= 0; k--, tans++) {
                            if (G[i + 1][k] != '1') {
                                break;
                            }
                        }
                        f[i + 1][j] = Math.max(f[i + 1][j], tans);
                        // System.out.println("0d %d %d -> %d".formatted(i + 1, j, tans));
                    }
                } else {
                    // right
                    if (j < G[i].length - 1) {
                        int minI;
                        for (minI = i; minI >= 0; minI--) {
                            if (G[minI][j] != '1') {
                                break;
                            }
                        }
                        minI++;
                        for (int k = minI; k <= i; k++) {
                            if (isFullOne(k, j - f[i][j] / (i - k + 1) + 1, i, j + 1)) {
                                f[i][j + 1] = Math.max(f[i][j + 1], (i - k + 1) * (j + 1 - (j - f[i][j] / (i - k + 1) + 1) + 1));
                                break;
                            }
                        }
                    }
                    // down
                    if (i < G.length - 1) {
                        int minJ;
                        for (minJ = j; minJ >= 0; minJ--) {
                            if (G[i][minJ] != '1') {
                                break;
                            }
                        }
                        minJ++;
                        for (int k = minJ; k <= j; k++) {
                            if (isFullOne(i - f[i][j] / (j - k + 1) + 1, k, i + 1, j)) {
                                // System.out.println("1d calc i=%d, j=%d, minJ=%d, k=%d".formatted(i, j, minJ, k));
                                f[i + 1][j] = Math.max(f[i + 1][j], (j - k + 1) * (i + 1 - (i - f[i][j] / (j - k + 1) + 1) + 1));
                                break;
                            }
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
        return ans;
    }
    boolean isFullOne(int x1, int y1, int x2, int y2) {
        int sum = d[x2][y2]
            - (x1 > 0 ? d[x1 - 1][y2] : 0)
            - (y1 > 0 ? d[x2][y1 - 1] : 0)
            + ((x1 > 0 && y1 > 0) ? d[x1 - 1][y1 - 1] : 0);
        return sum == (x2 - x1 + 1) * (y2 - y1 + 1);
    }
}