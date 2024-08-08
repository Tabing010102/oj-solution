class Solution {
    final int MAXN = 100 + 5;
    int[][] f = new int[MAXN][MAXN];
    public int uniquePaths(int m, int n) {
        f[0][0] = 1;
        for (int i = 0; i < m ; i++) {
            for (int j = 0; j < n ; j++) {
                if (i < m - 1) { f[i + 1][j] += f[i][j]; }
                if (j < n - 1) { f[i][j + 1] += f[i][j]; }
            }
        }
        return f[m - 1][n - 1];
    }
}