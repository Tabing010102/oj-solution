import java.util.*;

class Solution {
    public final int MAXN = 200 + 10;
    public final int INF = Integer.MAX_VALUE;
    List<List<Integer>> d;
    int[][] f;
    int dp(int i, int j) {
        if (i < j || j < 0) {
            return 0x3f3f3f3f;
        }
        if (i == 0) {
            return f[i][j] = d.get(i).get(j);
        }
        if (f[i][j] != -INF) {
            return f[i][j];
        }
        return f[i][j] = d.get(i).get(j) + Math.min(dp(i - 1, j), dp(i - 1, j - 1));
    }
    public int minimumTotal(List<List<Integer>> triangle) {
        d = triangle;
        f = new int[MAXN][MAXN];
        for (int i = 0; i < MAXN; i++) {
            Arrays.fill(f[i], -INF);
        }
        for (int i = 0; i < d.get(d.size() - 1).size(); i++) {
            dp(d.size() - 1, i);
        }
        int minVal = INF;
        for (int i = 0; i < d.get(d.size() - 1).size(); i++) {
            minVal = Math.min(f[d.size() - 1][i], minVal);
        }
        return minVal;
    }
}